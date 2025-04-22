<?php
$servername = "localhost";
$username = "root";
$password = "";
$dbname = "GymAdmin";

try {
    $pdo = new PDO("mysql:host=$servername;dbname=$dbname", $username, $password);
    $pdo->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
} catch (PDOException $e) {
    die("❌ Error de conexión: " . $e->getMessage());
}

if ($_SERVER["REQUEST_METHOD"] === "POST" && isset($_POST['HActId'], $_POST['HMemId'])) {
    $id_actividad = $_POST['HActId'];
    $id_miembro = $_POST['HMemId'];

    if (!empty($id_actividad) && !empty($id_miembro)) {
        try {
            $stmt = $pdo->prepare("DELETE FROM inscritos_act WHERE id_actividad = :id_actividad AND id_miembro = :id_miembro");
            $stmt->bindParam(':id_actividad', $id_actividad);
            $stmt->bindParam(':id_miembro', $id_miembro);

            if ($stmt->execute() && $stmt->rowCount() > 0) {
                echo "✅ Miembro dado de baja exitosamente de la actividad. ✅";
            } else {
                echo "⚠️ No se encontró un registro para esta combinación de actividad y miembro. ⚠️";
            }
        } catch (PDOException $e) {
            echo "❌ Error al procesar la baja: " . $e->getMessage();
        }
    } else {
        echo "❌ Datos incompletos proporcionados. ❌";
    }
} else {
    echo "❌ Solicitud no válida. ❌";
}
?>
