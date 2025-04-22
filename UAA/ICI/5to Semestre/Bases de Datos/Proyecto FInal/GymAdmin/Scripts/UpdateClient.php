<?php
$servername = "localhost";
$username = "root";
$password = "";
$dbname = "GymAdmin";

// Intentamos conectar a la base de datos
try {
    $pdo = new PDO("mysql:host=$servername;dbname=$dbname", $username, $password);
    $pdo->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
} catch (PDOException $e) {
    die(json_encode(["error" => "Error de conexión: " . $e->getMessage()]));
}

// Verificamos si los datos del formulario de actualización están presentes
if ($_SERVER["REQUEST_METHOD"] === "POST" && isset($_POST['Name'])) {
    $id_cliente = $_POST['Id'];
    $nombre = $_POST['Name'];
    $apellido = $_POST['LastName'];
    $telefono = $_POST['Tel'];

    // Verificamos que los campos necesarios no estén vacíos
    if (!empty($id_cliente) && !empty($nombre) && !empty($apellido) && !empty($telefono)) {
        // Preparamos la consulta SQL para actualizar los datos del cliente
        $stmt = $pdo->prepare("UPDATE clientes SET nombre = :nombre, apellido = :apellido, telefono = :telefono WHERE id_cliente = :id_cliente");
        $stmt->bindParam(':id_cliente', $id_cliente);
        $stmt->bindParam(':nombre', $nombre);
        $stmt->bindParam(':apellido', $apellido);
        $stmt->bindParam(':telefono', $telefono);

        // Ejecutamos la consulta
        if ($stmt->execute()) {
            echo "✅ Cliente actualizado exitosamente. ✅";
        } else {
            echo "❌ Error al actualizar el cliente. ❌";
        }
    } else {
        echo "❌ Todos los campos deben estar completos. ❌";
    }
} else {
    echo "❌ Datos del formulario no recibidos correctamente. ❌";
}
?>
