<?php
$pdo = new PDO("mysql:host=localhost;dbname=GymAdmin", "root", "");
$pdo->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);

$stmt = $pdo->query("SELECT id_cliente, id_miembro, fecha_inicio, fecha_vencimiento FROM miembros");
$miembros = $stmt->fetchAll(PDO::FETCH_ASSOC);

echo json_encode($miembros);
?>
