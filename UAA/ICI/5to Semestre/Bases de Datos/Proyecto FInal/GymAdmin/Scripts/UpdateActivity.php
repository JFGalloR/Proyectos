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
    $nombre = $_POST['Name'];
    $id_instructor = $_POST['InstructorId'];
    $hora_inicio = $_POST['H_Start'];
    $hora_final = $_POST['H_End'];
    $dias = [];

    foreach (['M', 'T', 'W', 'Th', 'F', 'S', 'Su'] as $dia) {
        if (isset($_POST[$dia])) {
            $dias[] = $dia;
        }
    }

    $stmt = $pdo->prepare("UPDATE actividades SET nombre = ?, id_instructor = ?, hora_inicio = ?, hora_final = ? WHERE id_actividad = ?");
    $stmt->execute([$nombre, $id_instructor, $hora_inicio, $hora_final, $id_actividad]);

    $stmt = $pdo->prepare("DELETE FROM dias_act WHERE id_actividad = ?");
    $stmt->execute([$id_actividad]);

    foreach ($dias as $dia) {
        $id_dia = getIdDia($pdo, $dia);
        $stmt = $pdo->prepare("INSERT INTO dias_act (id_actividad, id_dia) VALUES (?, ?)");
        $stmt->execute([$id_actividad, $id_dia]);
    }

    echo "✅ Actividad actualizada con éxito. ✅";
}

function getIdDia($pdo, $dia) {
    $dias = ['M' => 1, 'T' => 2, 'W' => 3, 'Th' => 4, 'F' => 5, 'S' => 6, 'Su' => 7];
    return $dias[$dia];
}
?>
