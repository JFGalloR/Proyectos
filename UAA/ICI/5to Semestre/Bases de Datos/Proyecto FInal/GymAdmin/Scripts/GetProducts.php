<?php
$pdo = new PDO("mysql:host=localhost;dbname=GymAdmin", "root", "");
$pdo->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);

$stmt = $pdo->query("SELECT id_producto, nombre, precio, stock FROM productos");
$productos = $stmt->fetchAll(PDO::FETCH_ASSOC);

echo json_encode(['success' => true, 'products' => $productos]);
?>
