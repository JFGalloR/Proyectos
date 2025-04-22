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

if ($_SERVER["REQUEST_METHOD"] === "POST" && isset($_POST['id_cliente'], $_POST['total'], $_POST['tipo_pago'], $_POST['productos'])) {
    $id_cliente = $_POST['id_cliente'];
    $total = $_POST['total'];
    $tipo_pago = $_POST['tipo_pago'];
    $productos = json_decode($_POST['productos'], true);

    $stmt = $pdo->prepare("SELECT id_cliente FROM clientes WHERE id_cliente = ?");
    $stmt->execute([$id_cliente]);
    $cliente = $stmt->fetch();

    if ($cliente) {
        try {
            $pdo->beginTransaction();

            $stmt = $pdo->prepare("INSERT INTO ventas (id_cliente, total, tipo_pago, fecha_operacion) VALUES (?, ?, ?, NOW())");
            $stmt->execute([$id_cliente, $total, $tipo_pago]);

            $id_operacion = $pdo->lastInsertId();

            foreach ($productos as $producto) {
                $stmt = $pdo->prepare("INSERT INTO detalle_venta (id_operacion, id_producto, cantidad, precio) VALUES (?, ?, ?, ?)");
                $stmt->execute([$id_operacion, $producto['id_producto'], $producto['cantidad'], $producto['precio']]);
            }

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
