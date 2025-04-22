<?php
$servername = "localhost";
$username = "root";
$password = "";
$dbname = "GymAdmin";

try {
    $pdo = new PDO("mysql:host=$servername;dbname=$dbname", $username, $password);
    $pdo->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
    
    $query = "
        SELECT a.id_actividad, a.nombre, 
            DATE_FORMAT(a.hora_inicio, '%H:%i') AS hora_inicio, 
            DATE_FORMAT(a.hora_final, '%H:%i') AS hora_final, 
            d.id_dia AS dia, i.nombre AS instructor_nombre, i.apellido AS instructor_apellido
        FROM actividades a
        JOIN dias_act da ON a.id_actividad = da.id_actividad
        JOIN dias_semana d ON da.id_dia = d.id_dia
        JOIN instructores i ON a.id_instructor = i.id_instructor
        ORDER BY d.id_dia, a.hora_inicio
    ";
    
    $stmt = $pdo->query($query);
    $activities = $stmt->fetchAll(PDO::FETCH_ASSOC);
    
    echo json_encode($activities);
} catch (PDOException $e) {
    die("Error: " . $e->getMessage());
}
?>
