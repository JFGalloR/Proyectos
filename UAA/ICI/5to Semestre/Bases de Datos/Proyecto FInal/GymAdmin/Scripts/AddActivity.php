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
    $id_instructor = $_POST['Id'];
    $hora_inicio = $_POST['H_Start'];
    $hora_final = $_POST['H_End'];

    try {
        $stmt = $pdo->prepare("INSERT INTO actividades (nombre, id_instructor, hora_inicio, hora_final) 
                               VALUES (:nombre, :id_instructor, :hora_inicio, :hora_final)");
        $stmt->bindParam(':nombre', $nombre);
        $stmt->bindParam(':id_instructor', $id_instructor);
        $stmt->bindParam(':hora_inicio', $hora_inicio);
        $stmt->bindParam(':hora_final', $hora_final);
        $stmt->execute();

        $id_actividad = $pdo->lastInsertId();

        $dias_seleccionados = ['M', 'T', 'W', 'Tr', 'F', 'S', 'Su'];
        foreach ($dias_seleccionados as $dia) {
            if (isset($_POST[$dia])) {
                // Insertar en la tabla 'dias_act'
                $stmt = $pdo->prepare("INSERT INTO dias_act (id_actividad, id_dia) 
                                       VALUES (:id_actividad, :id_dia)");
                $stmt->bindParam(':id_actividad', $id_actividad);
                $stmt->bindParam(':id_dia', $_POST[$dia]);
                $stmt->execute();
            }
        }

        echo "✅ Actividad registrada exitosamente ✅";
    } catch (PDOException $e) {
        echo "🛑 Error al registrar la actividad: " . $e->getMessage();
    }
}
?>
