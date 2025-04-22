<?php
$servername = "localhost";
$username = "root";
$password = "";
$dbname = "GymAdmin";

try {
    $pdo = new PDO("mysql:host=$servername;dbname=$dbname", $username, $password);
    $pdo->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);

    $query = "
        SELECT m.id_miembro, 
               CONCAT(c.nombre, ' ', c.apellido) AS nombre_completo,
               a.id_actividad,
               a.nombre AS nombre_actividad
        FROM miembros m
        JOIN clientes c ON m.id_cliente = c.id_cliente
        JOIN inscritos_act am ON m.id_miembro = am.id_miembro
        JOIN actividades a ON am.id_actividad = a.id_actividad
        ORDER BY m.id_miembro
    ";

    $stmt = $pdo->query($query);
    $members = $stmt->fetchAll(PDO::FETCH_ASSOC);

    echo json_encode($members);
} catch (PDOException $e) {
    die("Error: " . $e->getMessage());
}
?>
