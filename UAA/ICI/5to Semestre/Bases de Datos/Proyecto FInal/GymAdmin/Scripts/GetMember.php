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

if ($_SERVER["REQUEST_METHOD"] === "POST" && isset($_POST['IdMem'])) {
    $idMiembro = $_POST['IdMem'];

    if (!empty($idMiembro)) {
        $stmt = $pdo->prepare("
            SELECT CONCAT(c.nombre, ' ', c.apellido) AS nombreCompleto
            FROM miembros m
            INNER JOIN clientes c ON m.id_cliente = c.id_cliente
            WHERE m.id_miembro = :id_miembro
            LIMIT 1
        ");
        $stmt->bindParam(':id_miembro', $idMiembro);
        $stmt->execute();

        $miembro = $stmt->fetch(PDO::FETCH_ASSOC);
        if ($miembro) {
            echo json_encode($miembro);
        } else {
            echo json_encode(["error" => "Miembro no encontrado"]);
        }
    } else {
        echo json_encode(["error" => "ID de miembro no proporcionado"]);
    }
} else {
    echo json_encode(["error" => "Solicitud no válida"]);
}
?>
