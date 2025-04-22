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

if ($_SERVER["REQUEST_METHOD"] === "POST" && isset($_POST['ActId'])) {
    $id_actividad = $_POST['ActId'];

    $stmt = $pdo->prepare("DELETE FROM inscritos_act WHERE id_actividad = ?");
    $stmt->execute([$id_actividad]);

    $stmt = $pdo->prepare("DELETE FROM dias_act WHERE id_actividad = ?");
    $stmt->execute([$id_actividad]);

    $stmt = $pdo->prepare("DELETE FROM actividades WHERE id_actividad = ?");
    $stmt->execute([$id_actividad]);

    echo "✅ Actividad con ID: $id_actividad eliminada con éxito. ✅";
}
?>
