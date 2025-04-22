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

if ($_SERVER["REQUEST_METHOD"] === "POST" && isset($_POST['InsId'])) {
    $id_instructor = $_POST['InsId'];

    if (!empty($id_instructor)) {
        $stmt = $pdo->prepare("SELECT nombre, apellido, telefono, rfc FROM instructores WHERE id_instructor = :id_instructor LIMIT 1");
        $stmt->bindParam(':id_instructor', $id_instructor);
        $stmt->execute();

        $instructor = $stmt->fetch(PDO::FETCH_ASSOC);
        if ($instructor) {
            echo json_encode($instructor);
        } else {
            echo json_encode(["error" => "Instructor no encontrado"]);
        }
    } else {
        echo json_encode(["error" => "ID del instructor no proporcionado"]);
    }
} else {
    echo json_encode(["error" => "Solicitud no válida"]);
}
?>
