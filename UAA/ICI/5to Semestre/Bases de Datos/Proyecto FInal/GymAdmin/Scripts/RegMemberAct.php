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
            $stmt = $pdo->prepare("SELECT COUNT(*) FROM inscritos_act WHERE id_miembro = :id_miembro");
            $stmt->bindParam(':id_miembro', $id_miembro);
            $stmt->execute();
            $count = $stmt->fetchColumn();

            if ($count >= 3) {
                echo "❌ Límite de actividades por miembro alcanzado. ❌";
                exit;
            }

            $stmt = $pdo->prepare("INSERT INTO inscritos_act (id_actividad, id_miembro) VALUES (:id_actividad, :id_miembro)");
            $stmt->bindParam(':id_actividad', $id_actividad);
            $stmt->bindParam(':id_miembro', $id_miembro);

            if ($stmt->execute()) {
                echo "✅ Miembro inscrito exitosamente en la actividad. ✅";
            } else {
                echo "❌ Error al inscribir al miembro en la actividad. ❌";
            }
        } catch (PDOException $e) {
            echo "❌ Error al procesar la inscripción: " . $e->getMessage();
        }
    } else {
        echo "❌ Datos incompletos proporcionados. ❌";
    }
} else {
    echo "❌ Solicitud no válida. ❌";
}
?>
