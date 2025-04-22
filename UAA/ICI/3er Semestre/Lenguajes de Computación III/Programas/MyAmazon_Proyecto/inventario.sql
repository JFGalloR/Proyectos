-- phpMyAdmin SQL Dump
-- version 5.2.1
-- https://www.phpmyadmin.net/
--
-- Servidor: 127.0.0.1
-- Tiempo de generación: 21-11-2023 a las 09:32:03
-- Versión del servidor: 10.4.28-MariaDB
-- Versión de PHP: 8.2.4

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Base de datos: `myamazon`
--

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `inventario`
--

CREATE TABLE `inventario` (
  `clave` int(11) NOT NULL,
  `producto` varchar(255) DEFAULT NULL,
  `imagen` varchar(255) DEFAULT NULL,
  `categoria` varchar(255) DEFAULT NULL,
  `cantidad` int(11) DEFAULT NULL,
  `precio` float DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Volcado de datos para la tabla `inventario`
--

INSERT INTO `inventario` (`clave`, `producto`, `imagen`, `categoria`, `cantidad`, `precio`) VALUES
(1, 'Xbox Series S', '/MyAmazon/Images/Products/xboxseriess.png', 'Electrónicos', 6, 4599),
(2, 'iPhone 14', '/MyAmazon/Images/Products/iphone14.png', 'Electrónicos', 11, 22489),
(3, 'Lego City', '/MyAmazon/Images/Products/lego.png', 'Juguetes y Juegos', 9, 899),
(4, 'Gorra New Era', '/MyAmazon/Images/Products/gorra.png', 'Ropa y Accesorios', 19, 1299),
(5, 'Guitarra Eléctrica Fender', '/MyAmazon/Images/Products/guitarra.png', 'Música', 9, 2489),
(6, 'Thriller Michael Jackson', '/MyAmazon/Images/Products/disco.png', 'Música', 15, 999),
(7, 'Licuadora Oster', '/MyAmazon/Images/Products/licuadora.png', 'Electrodomésticos', 14, 1759),
(8, 'Taladro y complementos', '/MyAmazon/Images/Products/taladro.png', 'Herramientas', 15, 1599),
(9, 'Cheetos Flaming Hot', '/MyAmazon/Images/Products/chetos.png', 'Alimentos y Bebidas', 39, 45),
(10, 'Pants', '/MyAmazon/Images/Products/pants.png', 'Ropa y Accesorios', 19, 299),
(11, 'Limpiador de coche', '/MyAmazon/Images/Products/limpiador.png', 'Automotriz', 17, 436),
(12, 'Super Mario Odyssey', '/MyAmazon/Images/Products/mario.png', 'Videojuegos', 12, 1199),
(13, 'Galletas Oreo', '/MyAmazon/Images/Products/oreo.png', 'Alimentos y Bebidas', 27, 65),
(14, 'Refrigerador LG', '/MyAmazon/Images/Products/refrigerador.png', 'Electrodomésticos', 7, 15489),
(15, 'Cargador tipo C', '/MyAmazon/Images/Products/cargador.png', 'Electrónicos', 25, 125),
(16, 'Gotero de CBD', '/MyAmazon/Images/Products/cbd.png', 'Salud y Hogar', 22, 769),
(17, 'Sudadera', '/MyAmazon/Images/Products/sudadera.png', 'Ropa y Accesorios', 15, 689),
(18, 'Jägermeister', '/MyAmazon/Images/Products/Jagermeister.png', 'Alimentos y Bebidas', 8, 459),
(19, 'Red Dead Redemption 2', '/MyAmazon/Images/Products/rd2.png', 'Videojuegos', 19, 899),
(20, 'Air Jordan 1 Low', '/MyAmazon/Images/Products/airjordan1low.png', 'Ropa y Accesorios', 5, 2199),
(21, 'Bacardí', '/MyAmazon/Images/Products/bacardi.png', 'Alimentos y Bebidas', 19, 229),
(22, 'Martillo', '/MyAmazon/Images/Products/martillo.png', 'Herramientas', 12, 135),
(23, 'Cubierta Volante', '/MyAmazon/Images/Products/cubierta.png', 'Automotriz', 21, 269),
(24, 'Teclado Razer', '/MyAmazon/Images/Products/teclado.png', 'Electrónicos', 12, 799),
(25, 'Spider-man 2', '/MyAmazon/Images/Products/spiderman.png', 'Videojuegos', 24, 1599),
(26, 'Pistola de calor', '/MyAmazon/Images/Products/pistolacalor.png', 'Herramientas', 6, 789),
(27, 'El arte de la Guerra', '/MyAmazon/Images/Products/libro.png', 'Libros', 8, 749),
(28, 'Monitor Gamer', '/MyAmazon/Images/Products/monitor.png', 'Electrónicos', 9, 2099),
(29, 'Cinta métrica', '/MyAmazon/Images/Products/metrica.png', 'Herramientas', 8, 99),
(30, 'Echo Dot 5', '/MyAmazon/Images/Products/echo.png', 'Electrónicos', 15, 959),
(31, 'Dr Pepper', '/MyAmazon/Images/Products/drpepper.png', 'Alimentos y Bebidas', 22, 369),
(32, 'Memoria USB 128 gb', '/MyAmazon/Images/Products/memoria.png', 'Electrónicos', 15, 139);

--
-- Índices para tablas volcadas
--

--
-- Indices de la tabla `inventario`
--
ALTER TABLE `inventario`
  ADD PRIMARY KEY (`clave`);

--
-- AUTO_INCREMENT de las tablas volcadas
--

--
-- AUTO_INCREMENT de la tabla `inventario`
--
ALTER TABLE `inventario`
  MODIFY `clave` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=33;
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
