<?php
$servername = "localhost";
$username = "root";
$password = "";
$dbname = "GymAdmin";

try {
    $pdo = new PDO("mysql:host=$servername;dbname=$dbname", $username, $password);
    $pdo->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
} catch (PDOException $e) {
    die(json_encode(["error" => "Error de conexión: " . $e->getMessage()]));
}

if ($_SERVER["REQUEST_METHOD"] === "POST" && isset($_POST['Id'])) {
    $id_cliente = $_POST['Id'];

    if (!empty($id_cliente)) {
        $stmt = $pdo->prepare("SELECT nombre, apellido, telefono FROM clientes WHERE id_cliente = :id_cliente LIMIT 1");
        $stmt->bindParam(':id_cliente', $id_cliente);
        $stmt->execute();

        $cliente = $stmt->fetch(PDO::FETCH_ASSOC);
        if ($cliente) {
            echo json_encode($cliente);
        } else {
            echo json_encode(["error" => "Cliente no encontrado"]);
        }
    } else {
        echo json_encode(["error" => "ID del cliente no proporcionado"]);
    }
} else {
    echo json_encode(["error" => "Solicitud no válida"]);
}
?>
