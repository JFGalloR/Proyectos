<?php
$servername = "localhost";
$username = "root";
$password = "";
$dbname = "GymTrainingClub";

$conn = new mysqli($servername, $username, $password, $dbname);

if ($conn->connect_error) {
    die("Connection failed: " . $conn->connect_error);
}

if ($_SERVER["REQUEST_METHOD"] == "POST") {
    $id = $_POST['Id'];
    $name = $_POST['Name'];
    $lastName = $_POST['LastName'];
    $months = $_POST['Months'];

    $checkSql = "SELECT * FROM Miembros WHERE ID = '$id'";
    $result = $conn->query($checkSql);

    if ($result->num_rows > 0) {
        echo json_encode(["success" => false, "message" => "El ID ya existe en la base de datos"]);
    } else {
        $fechaIns = date('Y-m-d');
        
        $fechaVal = date('Y-m-d', strtotime("+$months months"));

        $sql = "INSERT INTO Miembros (ID, Nombre, Apellidos, Fecha_Ins, Fecha_Val)
                VALUES ('$id', '$name', '$lastName', '$fechaIns', '$fechaVal')";

        if ($conn->query($sql) === TRUE) {
            echo json_encode(["success" => true]);
        } else {
            echo json_encode(["success" => false, "message" => $conn->error]);
        }
    }

    $conn->close();
}
?>
