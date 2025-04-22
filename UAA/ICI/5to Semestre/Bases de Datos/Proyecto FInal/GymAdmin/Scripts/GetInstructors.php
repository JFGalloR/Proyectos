<?php
$servername = "localhost";
$username = "root";
$password = "";
$dbname = "GymAdmin";

try {
    $pdo = new PDO("mysql:host=$servername;dbname=$dbname", $username, $password);
    $pdo->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
    
    $query = "
        SELECT id_instructor, nombre, apellido, telefono, RFC, fecha_registro
        FROM instructores
        ORDER BY fecha_registro
    ";
    $stmt = $pdo->query($query);
    $instructors = $stmt->fetchAll(PDO::FETCH_ASSOC);
    
    echo json_encode($instructors);
} catch (PDOException $e) {
    die("Error: " . $e->getMessage());
}
?>
