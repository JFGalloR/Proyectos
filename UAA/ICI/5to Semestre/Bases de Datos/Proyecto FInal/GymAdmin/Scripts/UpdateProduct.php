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

if ($_SERVER["REQUEST_METHOD"] === "POST" && isset($_POST['IdProd'], $_POST['Name'], $_POST['Cant'], $_POST['Price'])) {
    $idProducto = $_POST['IdProd'];
    $nombre = $_POST['Name'];
    $cantidad = $_POST['Cant'];
    $precio = $_POST['Price'];

    $stmt = $pdo->prepare("UPDATE productos SET nombre = ?, stock = ?, precio = ? WHERE id_producto = ?");
    $stmt->execute([$nombre, $cantidad, $precio, $idProducto]);

    echo "✅ Producto modificado con éxito. ✅";
}
?>
