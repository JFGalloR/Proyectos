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

if ($_SERVER["REQUEST_METHOD"] === "POST" && isset($_POST['ActId'])) {
    $id_actividad = $_POST['ActId'];

    if (!empty($id_actividad)) {
        $stmt = $pdo->prepare("SELECT a.nombre, a.id_instructor, a.hora_inicio, a.hora_final
                               FROM actividades a
                               WHERE a.id_actividad = :id_actividad LIMIT 1");
        $stmt->bindParam(':id_actividad', $id_actividad);
        $stmt->execute();

        $actividad = $stmt->fetch(PDO::FETCH_ASSOC);

        if ($actividad) {
            $stmtDias = $pdo->prepare("SELECT id_dia FROM dias_act WHERE id_actividad = :id_actividad");
            $stmtDias->bindParam(':id_actividad', $id_actividad);
            $stmtDias->execute();
            $dias = $stmtDias->fetchAll(PDO::FETCH_COLUMN);

            $actividad['dias'] = $dias;
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
