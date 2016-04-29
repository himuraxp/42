-- phpMyAdmin SQL Dump
-- version 4.4.10
-- http://www.phpmyadmin.net
--
-- Host: localhost:8889
-- Generation Time: Apr 29, 2016 at 01:15 PM
-- Server version: 5.5.42
-- PHP Version: 7.0.0

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET time_zone = "+00:00";

--
-- Database: `camagru`
--

-- --------------------------------------------------------

--
-- Table structure for table `config`
--

CREATE TABLE `config` (
  `pattern` varchar(255) NOT NULL,
  `pass_pattern` varchar(255) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Table structure for table `pictures`
--

CREATE TABLE `pictures` (
  `id` int(11) NOT NULL,
  `title` varchar(255) CHARACTER SET utf8 NOT NULL,
  `url` varchar(255) CHARACTER SET utf8 NOT NULL,
  `comment` varchar(255) CHARACTER SET utf8 NOT NULL,
  `date` date NOT NULL,
  `published` varchar(255) NOT NULL,
  `user_id` varchar(255) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Table structure for table `users`
--

CREATE TABLE `users` (
  `Login` varchar(255) NOT NULL,
  `Mail` varchar(255) NOT NULL,
  `Password` varchar(255) NOT NULL,
  `active` int(11) DEFAULT NULL,
  `clef` varchar(255) NOT NULL,
  `date_inscription` date NOT NULL,
  `id_icon` int(11) NOT NULL,
  `role` varchar(255) NOT NULL,
  `images_dir` varchar(255) NOT NULL,
  `ID` int(10) unsigned NOT NULL
) ENGINE=InnoDB AUTO_INCREMENT=17 DEFAULT CHARSET=utf8;

--
-- Dumping data for table `users`
--

INSERT INTO `users` (`Login`, `Mail`, `Password`, `active`, `clef`, `date_inscription`, `id_icon`, `role`, `images_dir`, `ID`) VALUES
('himura', 'larbi_yohann@hotmail.com', '$2y$10$KnGvpq9Cj5ZaXaXejs0xuOgovra1/f17C0vD6wUgEByPzzIPU7CmS', 1, '226db5058e1da55fa531aaff01a427392773883b8c1fd62f0f2c78e65ec71a659fd91149616e4d378f7c44123b9684dbcbac2eacfeb0c2d2cefbbc80c1fa8d32', '2016-04-27', 1, 'user', '../img/himura', 15),
('maurice', 'nast07@hotmail.com', '$2y$10$ssT1pJ0tCDQjutY6GVBRd.9q/jhUB5O7uC31qixWS5fYsCiCFoYgu', 1, 'aed76369d5974e6c7b5c51e496a2307eb9ee732bf59cef3a05dfb370142931e3a56e35792c53668c6410cf547fd34697c6b931d4b62f00eacb2b6b643f785f61', '2016-04-28', 1, 'user', '../img/maurice', 16);

--
-- Indexes for dumped tables
--

--
-- Indexes for table `pictures`
--
ALTER TABLE `pictures`
  ADD PRIMARY KEY (`id`);

--
-- Indexes for table `users`
--
ALTER TABLE `users`
  ADD PRIMARY KEY (`ID`);

--
-- AUTO_INCREMENT for dumped tables
--

--
-- AUTO_INCREMENT for table `pictures`
--
ALTER TABLE `pictures`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT;
--
-- AUTO_INCREMENT for table `users`
--
ALTER TABLE `users`
  MODIFY `ID` int(10) unsigned NOT NULL AUTO_INCREMENT,AUTO_INCREMENT=17;
