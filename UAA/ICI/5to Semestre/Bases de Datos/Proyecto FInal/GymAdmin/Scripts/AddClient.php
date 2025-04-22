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
    $nombre = $_POST['Name'];
    $apellido = $_POST['LastName'];
    $telefono = $_POST['Tel'];

    try {
        $stmt = $pdo->prepare("INSERT INTO clientes (nombre, apellido, telefono) VALUES (:nombre, :apellido, :telefono)");
        $stmt->bindParam(':nombre', $nombre);
        $stmt->bindParam(':apellido', $apellido);
        $stmt->bindParam(':telefono', $telefono);

        if ($stmt->execute()) {
            $id_cliente = $pdo->lastInsertId();
            echo "✅ Cliente registrado exitosamente con el ID: #$id_cliente ✅";
        } else {
            echo "❌ Error al registrar el cliente. ❌";
        }
    } catch (PDOException $e) {
        echo "🛑 Error en la consulta: " . $e->getMessage();
    }
}
?>
