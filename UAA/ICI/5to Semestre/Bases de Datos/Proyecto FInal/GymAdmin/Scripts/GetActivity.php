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

if ($_SERVER["REQUEST_METHOD"] === "POST" && isset($_POST['IdAct'])) {
    $idActividad = $_POST['IdAct'];

    if (!empty($idActividad)) {
        $stmt = $pdo->prepare("SELECT nombre FROM actividades WHERE id_actividad = :id_actividad LIMIT 1");
        $stmt->bindParam(':id_actividad', $idActividad);
        $stmt->execute();

        $actividad = $stmt->fetch(PDO::FETCH_ASSOC);
        if ($actividad) {
            echo json_encode($actividad);
        } else {
            echo json_encode(["error" => "Actividad no encontrada"]);
        }
    } else {
        echo json_encode(["error" => "ID de actividad no proporcionado"]);
    }
} else {
    echo json_encode(["error" => "Solicitud no válida"]);
}
?>
