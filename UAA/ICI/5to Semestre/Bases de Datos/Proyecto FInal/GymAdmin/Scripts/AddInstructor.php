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
    $rfc = $_POST['RFC'];
    $fecha_registro = date('Y-m-d H:i:s');

    try {
        $stmt = $pdo->prepare("INSERT INTO instructores (nombre, apellido, telefono, RFC, fecha_registro) 
                               VALUES (:nombre, :apellido, :telefono, :rfc, :fecha_registro)");
        $stmt->bindParam(':nombre', $nombre);
        $stmt->bindParam(':apellido', $apellido);
        $stmt->bindParam(':telefono', $telefono);
        $stmt->bindParam(':rfc', $rfc);
        $stmt->bindParam(':fecha_registro', $fecha_registro);

        if ($stmt->execute()) {
            echo "✅ Instructor registrado exitosamente ✅";
        } else {
            echo "❌ Error al registrar el instructor ❌";
        }
    } catch (PDOException $e) {
        echo "🛑 Error en la consulta: " . $e->getMessage();
    }
}
?>
