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

if ($_SERVER["REQUEST_METHOD"] === "POST" && isset($_POST['id_producto'], $_POST['cantidad'])) {
    $id_producto = $_POST['id_producto'];
    $cantidad = $_POST['cantidad'];

    try {
        // Actualizar el stock del producto
        $stmt = $pdo->prepare("UPDATE productos SET stock = stock - ? WHERE id_producto = ?");
        $stmt->execute([$cantidad, $id_producto]);

        if ($stmt->rowCount() > 0) {
            echo json_encode(['success' => true]);
        } else {
            echo json_encode(['success' => false, 'message' => 'No se pudo actualizar el stock']);
        }
    } catch (Exception $e) {
        echo json_encode(['success' => false, 'message' => 'Error al actualizar el stock: ' . $e->getMessage()]);
    }
}
?>
