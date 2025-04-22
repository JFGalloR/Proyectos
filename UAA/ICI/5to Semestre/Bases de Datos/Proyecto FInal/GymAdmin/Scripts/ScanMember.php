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

if ($_SERVER["REQUEST_METHOD"] === "POST" && isset($_POST['Code'])) {
    $idMiembro = $_POST['Code'];

    if (!empty($idMiembro)) {
        $stmt = $pdo->prepare("
            SELECT 
                c.nombre, 
                c.apellido, 
                c.fecha_registro, 
                m.fecha_inicio, 
                m.fecha_vencimiento
            FROM miembros m
            INNER JOIN clientes c ON m.id_cliente = c.id_cliente
            WHERE m.id_miembro = :id_miembro
            LIMIT 1
        ");
        $stmt->bindParam(':id_miembro', $idMiembro);
        $stmt->execute();

        $miembro = $stmt->fetch(PDO::FETCH_ASSOC);

        if ($miembro) {
            echo json_encode([
                'nombre' => $miembro['nombre'],
                'apellido' => $miembro['apellido'],
                'fecha_registro' => $miembro['fecha_registro'],
                'fecha_inicio' => $miembro['fecha_inicio'],
                'fecha_vencimiento' => $miembro['fecha_vencimiento']
            ]);
        } else {
            echo json_encode(["error" => "⚠️ Miembro no encontrado. ⚠️"]);
        }
    } else {
        echo json_encode(["error" => "❌ ID de miembro no proporcionado. ❌"]);
    }
} else {
    echo json_encode(["error" => "❌ Solicitud no válida. ❌"]);
}
?>
