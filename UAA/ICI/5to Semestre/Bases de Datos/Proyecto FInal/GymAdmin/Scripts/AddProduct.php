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

if ($_SERVER["REQUEST_METHOD"] === "POST" && isset($_POST['Id'], $_POST['Name'], $_POST['Cant'], $_POST['Price'])) {
    $codigo = $_POST['Id'];
    $nombre = $_POST['Name'];
    $cantidad = $_POST['Cant'];
    $precio = $_POST['Price'];

    $stmt = $pdo->prepare("INSERT INTO productos (id_producto, nombre, stock, precio) VALUES (?, ?, ?, ?)");
    $stmt->execute([$codigo, $nombre, $cantidad, $precio]);

    echo "✅ Producto agregado con éxito. ✅";
}
?>
