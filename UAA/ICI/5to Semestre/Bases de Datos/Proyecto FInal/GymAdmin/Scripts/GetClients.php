<?php
$pdo = new PDO("mysql:host=localhost;dbname=GymAdmin", "root", "");
$pdo->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);

$stmt = $pdo->query("SELECT id_cliente, nombre, apellido, telefono, fecha_registro FROM clientes");
$clientes = $stmt->fetchAll(PDO::FETCH_ASSOC);

echo json_encode($clientes);
?>
