<?php
$host = "localhost";
$username = "root";
$password = "";
$dbname = "GymAdmin";

try {
    $pdo = new PDO("mysql:host=$host;dbname=$dbname", $username, $password);
    $pdo->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
} catch (PDOException $e) {
    echo json_encode(['success' => false, 'message' => 'Conexión fallida: ' . $e->getMessage()]);
    exit;
}

// Verificar la acción solicitada
if ($_SERVER['REQUEST_METHOD'] === 'POST') {
    if (isset($_POST['action'])) {
        $action = $_POST['action'];

        // Acción para obtener los datos
        if ($action === 'getDatos') {
            // Obtener la cantidad total de miembros
            $stmt = $pdo->query("SELECT COUNT(*) FROM clientes");
            $totalMiembros = $stmt->fetchColumn();

            // Obtener la cantidad de miembros registrados hoy
            $stmt = $pdo->query("SELECT COUNT(*) FROM clientes WHERE DATE(fecha_registro) = CURDATE()");
            $miembrosHoy = $stmt->fetchColumn();

            // Obtener los totales de ventas
            $stmt = $pdo->query("SELECT SUM(total) FROM ventas");
            $acumuladoInventario = $stmt->fetchColumn();

            // Obtener las ventas de hoy
            $stmt = $pdo->query("SELECT SUM(total) FROM ventas WHERE DATE(fecha_operacion) = CURDATE()");
            $vendidoHoy = $stmt->fetchColumn();

            // Obtener el precio de inscripción y mensualidad (productos con id 0 y 1)
            $stmt = $pdo->prepare("SELECT precio FROM productos WHERE id_producto IN (0, 1)");
            $stmt->execute();
            $productos = $stmt->fetchAll(PDO::FETCH_ASSOC);
            $precioInscripcion = $productos[0]['precio'];
            $precioMensualidad = $productos[1]['precio'];

            // Enviar los datos como respuesta JSON
            echo json_encode([
                'success' => true,
                'totalMiembros' => $totalMiembros,
                'miembrosHoy' => $miembrosHoy,
                'acumuladoInventario' => $acumuladoInventario,
                'vendidoHoy' => $vendidoHoy,
                'precioInscripcion' => $precioInscripcion,
                'precioMensualidad' => $precioMensualidad
            ]);
        }

        // Acción para modificar precios
        if ($action === 'modificarPrecio') {
            $idProducto = $_POST['idProducto']; // 0 para inscripción, 1 para mensualidad
            $nuevoPrecio = $_POST['nuevoPrecio'];

            // Validar que el precio es un número positivo
            if (!is_numeric($nuevoPrecio) || $nuevoPrecio < 0) {
                echo json_encode(['success' => false, 'message' => 'Precio inválido']);
                exit;
            }

            // Actualizar el precio en la base de datos
            $stmt = $pdo->prepare("UPDATE productos SET precio = :nuevoPrecio WHERE id_producto = :idProducto");
            $stmt->bindParam(':nuevoPrecio', $nuevoPrecio, PDO::PARAM_STR);
            $stmt->bindParam(':idProducto', $idProducto, PDO::PARAM_INT);

            if ($stmt->execute()) {
                echo json_encode(['success' => true, 'message' => 'Precio actualizado correctamente']);
            } else {
                echo json_encode(['success' => false, 'message' => 'Error al actualizar el precio']);
            }
        }
    }
}
?>