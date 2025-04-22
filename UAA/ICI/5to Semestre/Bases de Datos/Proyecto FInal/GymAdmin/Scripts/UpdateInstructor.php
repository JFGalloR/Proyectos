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

if ($_SERVER["REQUEST_METHOD"] === "POST" && isset($_POST['InsId'])) {
    $insId = $_POST['InsId'];
    $insName = $_POST['InsName'];
    $insLastName = $_POST['InsLastName'];
    $insTel = $_POST['InsTel'];
    $insRFC = $_POST['InsRFC'];

    if (!empty($insId) && !empty($insName) && !empty($insLastName) && !empty($insTel) && !empty($insRFC)) {
        $stmt = $pdo->prepare("UPDATE instructores SET nombre = :nombre, apellido = :apellido, telefono = :telefono, rfc = :rfc WHERE id_instructor = :id_instructor");
        
        $stmt->bindParam(':id_instructor', $insId);
        $stmt->bindParam(':nombre', $insName);
        $stmt->bindParam(':apellido', $insLastName);
        $stmt->bindParam(':telefono', $insTel);
        $stmt->bindParam(':rfc', $insRFC);

        if ($stmt->execute()) {
            echo "✅ Datos del instructor actualizados correctamente. ✅";
        } else {
            echo "❌ Error al actualizar los datos del instructor. ❌";
        }
    } else {
        echo "❌ Todos los campos son requeridos. ❌";
    }
} else {
    echo "❌ Solicitud no válida. ❌";
}
?>
