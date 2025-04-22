<?php
$servername = "localhost";
$username = "root";
$password = "";
$dbname = "GymAdmin";

try {
    $pdo = new PDO("mysql:host=$servername;dbname=$dbname", $username, $password);
    $pdo->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
} catch (PDOException $e) {
    die("Error de conexión: " . $e->getMessage());
}

if ($_SERVER["REQUEST_METHOD"] === "POST" && isset($_POST['id_miembro'], $_POST['total'], $_POST['tipo_pago'], $_POST['productos'], $_POST['meses'])) {
    $id_miembro = $_POST['id_miembro'];
    $total = $_POST['total'];
    $tipo_pago = $_POST['tipo_pago'];
    $productos = json_decode($_POST['productos'], true);
    $meses = (int)$_POST['meses'];

    if ($productos === null) {
        echo json_encode(['success' => false, 'message' => '⚠️ Error en los productos enviados. ⚠️']);
        exit;
    }

    if ($meses <= 0) {
        echo json_encode(['success' => false, 'message' => '⚠️ El número de meses debe ser mayor que 0. ⚠️']);
        exit;
    }

    $stmt = $pdo->prepare("SELECT id_cliente, fecha_vencimiento FROM miembros WHERE id_miembro = ?");
    $stmt->execute([$id_miembro]);
    $result = $stmt->fetch();

    if ($result) {
        $id_cliente = $result['id_cliente'];
        $fecha_vencimiento_actual = $result['fecha_vencimiento'];
        $fecha_actual = new DateTime();
        $fecha_vencimiento = new DateTime($fecha_vencimiento_actual);

        if ($fecha_vencimiento < $fecha_actual) {
            $fecha_vencimiento = $fecha_actual;
        }

        $fecha_vencimiento->modify("+$meses months");

        try {
            $pdo->beginTransaction();

            $stmt = $pdo->prepare("INSERT INTO ventas (id_cliente, total, tipo_pago, fecha_operacion) VALUES (?, ?, ?, NOW())");
            $stmt->execute([$id_cliente, $total, $tipo_pago]);

            $id_operacion = $pdo->lastInsertId();

            foreach ($productos as $producto) {
                $stmt = $pdo->prepare("INSERT INTO detalle_venta (id_operacion, id_producto, cantidad, precio) VALUES (?, ?, ?, ?)");
                $stmt->execute([$id_operacion, $producto['id_producto'], $producto['cantidad'], $producto['precio']]);
            }

            $stmt = $pdo->prepare("UPDATE miembros SET fecha_vencimiento = ? WHERE id_miembro = ?");
            $stmt->execute([$fecha_vencimiento->format("Y-m-d H:i:s"), $id_miembro]);

            $pdo->commit();

            echo json_encode(['success' => true]);

        } catch (Exception $e) {
            $pdo->rollBack();
            echo json_encode(['success' => false, 'message' => '🛑 Error al realizar la venta: ' . $e->getMessage()]);
        }
    } else {
        echo json_encode(['success' => false, 'message' => '⚠️ El cliente no existe. ⚠️']);
    }
}
?>
