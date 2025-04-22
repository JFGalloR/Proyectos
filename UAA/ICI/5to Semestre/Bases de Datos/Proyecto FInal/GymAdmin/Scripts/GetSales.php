<?php
$pdo = new PDO("mysql:host=localhost;dbname=GymAdmin", "root", "");
$pdo->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);

$stmt = $pdo->prepare("
    SELECT 
        v.fecha_operacion AS fecha_operacion,
        p.nombre, 
        dv.cantidad, 
        v.tipo_pago, 
        (dv.cantidad * p.precio) AS total
    FROM ventas v
    JOIN detalle_venta dv ON v.id_operacion = dv.id_operacion
    JOIN productos p ON dv.id_producto = p.id_producto
    WHERE DATE(v.fecha_operacion) = CURDATE()
");
$stmt->execute();
$ventas = $stmt->fetchAll(PDO::FETCH_ASSOC);

$stmtTotal = $pdo->prepare("
    SELECT 
        v.tipo_pago, 
        SUM(dv.cantidad * p.precio) AS total_pago
    FROM ventas v
    JOIN detalle_venta dv ON v.id_operacion = dv.id_operacion
    JOIN productos p ON dv.id_producto = p.id_producto
    WHERE DATE(v.fecha_operacion) = CURDATE()
    GROUP BY v.tipo_pago
");
$stmtTotal->execute();
$totales = $stmtTotal->fetchAll(PDO::FETCH_ASSOC);

if (empty($ventas)) {
    $ventas = [
        [
            'fecha_operacion' => 'No hay registros',
            'nombre' => '',
            'cantidad' => '',
            'tipo_pago' => '',
            'total' => '0.00'
        ]
    ];
}

echo json_encode([
    'success' => true,
    'ventas' => $ventas,
    'totales' => $totales
]);
?>
