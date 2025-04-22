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

if ($_SERVER["REQUEST_METHOD"] === "POST") {
    $id_cliente = $_POST['Id'];
    $months = $_POST['Months'];
    $tipo_pago = $_POST['MPay'];
    
    $stmt_inscripcion = $pdo->prepare("SELECT precio FROM productos WHERE id_producto = 0 LIMIT 1");
    $stmt_inscripcion->execute();
    $precio_inscripcion = $stmt_inscripcion->fetchColumn();

    $stmt_mensualidad = $pdo->prepare("SELECT precio FROM productos WHERE id_producto = 1 LIMIT 1");
    $stmt_mensualidad->execute();
    $precio_mensualidad = $stmt_mensualidad->fetchColumn();

    if ($precio_inscripcion === false || $precio_mensualidad === false) {
        die("🛑 Error: No se pudieron obtener los precios de los productos.");
    }

    $cantidad_meses = intval($months);

    $fecha_inicio = date("Y-m-d H:i:s");

    $fecha_vencimiento = date("Y-m-d H:i:s", strtotime("+$months months", strtotime($fecha_inicio)));

    $total_inscripcion = $precio_inscripcion;
    $total_mensualidad = $precio_mensualidad * $cantidad_meses;
    $total = $total_inscripcion + $total_mensualidad;

    try {
        $pdo->beginTransaction();

        $stmt_miembro = $pdo->prepare("INSERT INTO miembros (id_cliente, fecha_vencimiento, fecha_inicio) VALUES (:id_cliente, :fecha_vencimiento, NOW())");
        $stmt_miembro->bindParam(':id_cliente', $id_cliente);
        $stmt_miembro->bindParam(':fecha_vencimiento', $fecha_vencimiento);
        $stmt_miembro->execute();
        
        $id_miembro = $pdo->lastInsertId();
        
        $stmt_venta = $pdo->prepare("INSERT INTO ventas (id_cliente, total, tipo_pago, fecha_operacion) VALUES (:id_cliente, :total, :tipo_pago, NOW())");
        $stmt_venta->bindParam(':id_cliente', $id_cliente);
        $stmt_venta->bindParam(':total', $total);
        $stmt_venta->bindParam(':tipo_pago', $tipo_pago);
        $stmt_venta->execute();
        
        $id_operacion = $pdo->lastInsertId();
        
        $stmt_detalle_inscripcion = $pdo->prepare("INSERT INTO detalle_venta (id_operacion, id_producto, cantidad, precio) VALUES (:id_operacion, :id_producto, :cantidad, :precio)");
        $stmt_detalle_inscripcion->bindParam(':id_operacion', $id_operacion);
        $stmt_detalle_inscripcion->bindValue(':id_producto', 0);
        $stmt_detalle_inscripcion->bindValue(':cantidad', 1);
        $stmt_detalle_inscripcion->bindValue(':precio', $precio_inscripcion);
        $stmt_detalle_inscripcion->execute();
        
        $stmt_detalle_mensualidad = $pdo->prepare("INSERT INTO detalle_venta (id_operacion, id_producto, cantidad, precio) VALUES (:id_operacion, :id_producto, :cantidad, :precio)");
        $stmt_detalle_mensualidad->bindParam(':id_operacion', $id_operacion);
        $stmt_detalle_mensualidad->bindValue(':id_producto', 1);
        $stmt_detalle_mensualidad->bindValue(':cantidad', $cantidad_meses);
        $stmt_detalle_mensualidad->bindValue(':precio', $precio_mensualidad);
        $stmt_detalle_mensualidad->execute();

        $pdo->commit();

        echo "✅ Miembro registrado exitosamente con ID: #$id_miembro ✅";
    } catch (PDOException $e) {
        $pdo->rollBack();
        echo "🛑 Error al registrar los datos: " . $e->getMessage();
    }
}
?>
