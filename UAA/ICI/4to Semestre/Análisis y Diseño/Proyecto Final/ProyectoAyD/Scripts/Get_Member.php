<?php
$servername = "localhost";
$username = "root";
$password = "";
$dbname = "GymTrainingClub";

// Conectarse a la base de datos
$conn = new mysqli($servername, $username, $password, $dbname);

// Verificar conexión
if ($conn->connect_error) {
    echo json_encode(['success' => false, 'message' => 'Error en la conexión: ' . $conn->connect_error]);
    exit();
}

if ($_SERVER['REQUEST_METHOD'] == 'POST') {
    if (isset($_POST['searchInput'])) {
        $searchInput = $_POST['searchInput'];

        // Consulta preparada para evitar inyecciones SQL
        $stmt = $conn->prepare("SELECT * FROM Miembros WHERE ID = '$searchInput'");
        $stmt->execute();
        $result = $stmt->get_result();

        if ($result->num_rows > 0) {
            $row = $result->fetch_assoc();
            echo json_encode([
                'success' => true,
                'Id' => $searchInput,
                'Nombre' => $row['Nombre'],
                'Apellidos' => $row['Apellidos'],
                'Fecha_Ins' => $row['Fecha_Ins'],
                'Fecha_Val' => $row['Fecha_Val']
            ]);
        } else {
            echo json_encode(['success' => false, 'message' => 'No se encontraron resultados']);
        }

        $stmt->close();
    } else {
        echo json_encode(['success' => false, 'message' => 'No se proporcionó ningún ID']);
    }
}

$conn->close();
?>
