-- phpMyAdmin SQL Dump
-- version 4.8.2
-- https://www.phpmyadmin.net/
--
-- Anamakine: localhost
-- Üretim Zamanı: 19 Ağu 2018, 12:35:03
-- Sunucu sürümü: 10.1.34-MariaDB
-- PHP Sürümü: 7.2.8

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET AUTOCOMMIT = 0;
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Veritabanı: `testdb`
--

-- --------------------------------------------------------

--
-- Tablo için tablo yapısı `testtable`
--

CREATE TABLE `testtable` (
  `id` int(11) NOT NULL,
  `field1` varchar(11) NOT NULL,
  `field2` date NOT NULL,
  `field3` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf16;

--
-- Tablo döküm verisi `testtable`
--

INSERT INTO `testtable` (`id`, `field1`, `field2`, `field3`) VALUES
(1, 'deneme', '2018-01-01', 11),
(2, 'test', '2018-03-11', 25),
(3, 'değer', '2015-01-24', 96),
(4, 'oku', '2018-06-19', 421),
(5, 'yeni kayıt', '2017-09-08', 60),
(6, 'yeni kayıt', '2017-09-08', 60),
(7, 'yeni kayıt', '2017-09-08', 60),
(8, 'yeni kayıt', '2017-09-08', 60),
(9, 'yeni kayıt', '2017-09-08', 60),
(10, 'yeni kayıt', '2017-09-08', 60),
(11, 'yeni kayıt', '2017-09-08', 60),
(12, 'yeni kayıt', '2017-09-08', 60),
(13, 'yeni kayıt', '2017-09-08', 60);

--
-- Dökümü yapılmış tablolar için indeksler
--

--
-- Tablo için indeksler `testtable`
--
ALTER TABLE `testtable`
  ADD PRIMARY KEY (`id`);

--
-- Dökümü yapılmış tablolar için AUTO_INCREMENT değeri
--

--
-- Tablo için AUTO_INCREMENT değeri `testtable`
--
ALTER TABLE `testtable`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=14;
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
