-- phpMyAdmin SQL Dump
-- version 4.4.10
-- http://www.phpmyadmin.net
--
-- Client :  localhost:8889
-- Généré le :  Lun 26 Septembre 2016 à 09:28
-- Version du serveur :  5.5.42
-- Version de PHP :  7.0.0

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET time_zone = "+00:00";

--
-- Base de données :  `matcha`
--

-- --------------------------------------------------------

--
-- Structure de la table `likes`
--

CREATE TABLE `likes` (
  `id` int(11) NOT NULL,
  `user_id` int(8) DEFAULT NULL,
  `like_you` int(8) DEFAULT NULL,
  `you_like` int(8) DEFAULT NULL,
  `created_at` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP
) ENGINE=InnoDB AUTO_INCREMENT=66 DEFAULT CHARSET=latin1;

--
-- Contenu de la table `likes`
--

INSERT INTO `likes` (`id`, `user_id`, `like_you`, `you_like`, `created_at`) VALUES
(2, 57, 56, 57, '2016-08-17 15:41:58'),
(5, 60, 56, 60, '2016-08-17 15:56:08'),
(10, 56, 59, 56, '2016-08-17 16:03:27'),
(11, 58, 59, 58, '2016-08-18 12:27:40'),
(12, 58, 60, 58, '2016-08-18 12:27:56'),
(13, 56, 57, 56, '2016-08-18 12:28:45'),
(15, 59, 58, 59, '2016-08-18 12:40:37'),
(18, 55, 59, 55, '2016-08-24 18:02:08'),
(22, 57, 55, 57, '2016-08-24 18:42:41'),
(47, 59, 55, 59, '2016-08-25 10:38:40'),
(48, 61, 58, 61, '2016-08-25 10:45:32'),
(49, 61, 56, 61, '2016-08-25 10:45:34'),
(50, 62, 61, 62, '2016-08-25 10:52:32'),
(51, 62, 58, 62, '2016-08-25 10:52:33'),
(52, 64, 63, 64, '2016-08-25 11:02:50'),
(53, 61, 62, 61, '2016-08-25 11:11:51'),
(54, 55, 57, 55, '2016-08-25 11:41:52'),
(55, 56, 55, 56, '2016-08-25 11:46:43'),
(56, 64, 55, 64, '2016-08-25 11:46:59'),
(57, 58, 55, 58, '2016-08-25 11:47:19'),
(58, 61, 55, 61, '2016-08-25 11:47:36'),
(59, 55, 60, 55, '2016-08-25 14:05:39'),
(63, 60, 55, 60, '2016-09-24 12:18:50'),
(65, 55, 61, 55, '2016-09-24 16:32:48');

-- --------------------------------------------------------

--
-- Structure de la table `messages`
--

CREATE TABLE `messages` (
  `id` int(8) NOT NULL,
  `content` varchar(255) NOT NULL,
  `created_at` datetime NOT NULL,
  `user_id` int(11) NOT NULL,
  `message` varchar(255) DEFAULT NULL,
  `for_user_id` int(11) NOT NULL
) ENGINE=InnoDB AUTO_INCREMENT=59 DEFAULT CHARSET=latin1;

--
-- Contenu de la table `messages`
--

INSERT INTO `messages` (`id`, `content`, `created_at`, `user_id`, `message`, `for_user_id`) VALUES
(1, 'azeaze', '2016-08-09 12:50:03', 56, 'Il est trop fou ce message', 0),
(2, 'azeaze', '2016-08-09 12:50:52', 55, 'oui c''est vraiment malade', 59),
(4, '', '2016-08-17 15:02:05', 56, 'tu es sur ? ', 0),
(5, '', '2016-08-17 15:03:16', 56, 'oui c''est sur', 0),
(6, '', '2016-08-17 15:05:58', 56, 'aze', 0),
(7, '', '2016-08-17 15:07:17', 56, 'aze', 0),
(8, '', '2016-08-17 15:07:44', 56, 're test', 0),
(9, '', '2016-08-17 15:32:23', 55, 'Test', 59),
(10, '', '2016-08-17 15:32:35', 55, 'retestetesdqdfqsd', 59),
(11, '', '2016-08-17 15:36:45', 55, 'aze', 57),
(12, '', '2016-08-17 16:10:21', 56, 'Il commence a être pas mal ce petit chat', 0),
(13, '', '2016-08-17 16:11:02', 55, 'Oui mais il y a encore quelques modif a faire', 57),
(14, '', '2016-08-17 16:12:23', 56, 'Oui il y a un pb', 0),
(15, '', '2016-08-17 16:12:32', 55, 'tu crois', 60),
(16, '', '2016-08-17 16:18:45', 56, 'test', 0),
(17, '', '2016-08-17 16:18:49', 55, 'retest', 60),
(18, '', '2016-08-17 17:01:43', 55, 'Salut', 60),
(19, '', '2016-08-17 17:02:11', 55, 'Salut', 60),
(20, '', '2016-08-17 17:02:25', 55, 'Alors quoi de neuf ?', 60),
(21, '', '2016-08-17 17:04:01', 55, 'test', 0),
(22, '', '2016-08-17 17:07:25', 56, 'Salut', 0),
(23, '', '2016-08-17 17:07:40', 56, 'comment vas tu ?', 0),
(24, '', '2016-08-17 17:07:48', 55, 'Bien merci et toi', 60),
(25, '', '2016-08-17 17:07:59', 56, 'la forme ;)', 0),
(26, '', '2016-08-17 17:17:24', 55, 'Test', 57),
(27, '', '2016-08-17 17:34:07', 57, 'Yep', 0),
(28, '', '2016-08-17 17:37:08', 55, 'Salut a tous', 59),
(29, '', '2016-08-17 17:37:13', 56, 'Comment vas ?', 0),
(30, '', '2016-08-17 17:37:24', 57, 'Super merci et vous la forme ?', 55),
(31, '', '2016-08-17 17:37:33', 55, 'Oui tres bien', 59),
(32, '', '2016-08-17 17:37:39', 55, 'sinon quoi de neuf', 59),
(33, '', '2016-08-17 17:39:45', 57, 'C''est de la bombe se chat', 55),
(34, '', '2016-08-17 18:02:46', 60, 'Bonjour a tous', 55),
(35, '', '2016-08-17 20:34:37', 55, 'Test', 59),
(36, '', '2016-08-17 21:13:54', 60, 'test', 0),
(37, '', '2016-08-18 10:53:57', 55, 'test', 0),
(38, '', '2016-08-18 11:47:44', 55, 'test', 57),
(39, '', '2016-08-18 11:49:24', 55, 'tetet', 57),
(40, '', '2016-08-18 11:53:06', 55, 'new', 57),
(41, '', '2016-08-18 11:53:16', 55, 'renew', 57),
(42, '', '2016-08-18 11:53:36', 55, 'tout a l''aire OK', 57),
(43, '', '2016-08-18 12:29:34', 55, 'test scar', 57),
(44, '', '2016-08-18 12:29:46', 55, 'Test mila', 57),
(45, '', '2016-08-18 12:34:03', 55, 'Re coucou', 59),
(46, '', '2016-08-18 12:34:23', 55, 'Du coup comment vas ?', 60),
(47, '', '2016-08-18 12:34:39', 55, 'Coucou', 58),
(48, '', '2016-08-18 13:45:44', 55, 'test', 0),
(49, '', '2016-08-18 14:28:24', 58, 'test', 0),
(50, '', '2016-08-18 14:29:20', 56, 'Salut', 57),
(51, '', '2016-08-18 14:29:27', 56, 'Comment vas ?', 57),
(52, '', '2016-08-18 14:29:54', 57, 'Je vais bien toi ?', 56),
(53, '', '2016-08-18 14:30:12', 57, 'C''est quoi tous c''est test ?', 55),
(54, '', '2016-08-18 14:39:43', 57, 'Il me tarde que tous marche', 55),
(55, '', '2016-08-18 14:39:51', 57, 'Alors ?', 56),
(56, '', '2016-08-18 14:40:52', 59, 'Salut beau gosse', 58),
(57, '', '2016-08-18 14:41:24', 59, 'Desolé d''avoir mis autant de temps a te repondre', 55),
(58, '', '2016-08-22 10:01:46', 55, 'Coucou', 0);

-- --------------------------------------------------------

--
-- Structure de la table `notifications`
--

CREATE TABLE `notifications` (
  `id` int(8) NOT NULL,
  `user_id` int(8) NOT NULL,
  `like_you` int(8) NOT NULL,
  `active` tinyint(1) NOT NULL,
  `content` text NOT NULL
) ENGINE=InnoDB AUTO_INCREMENT=78 DEFAULT CHARSET=latin1;

--
-- Contenu de la table `notifications`
--

INSERT INTO `notifications` (`id`, `user_id`, `like_you`, `active`, `content`) VALUES
(1, 57, 55, 0, 'Vous avez eu un like de '),
(2, 57, 55, 0, 'Vous avez eu un like de '),
(3, 55, 57, 0, 'Vous avez eu un like de '),
(4, 55, 59, 0, 'Vous avez eu un like de '),
(5, 55, 60, 0, 'Vous avez eu un like de '),
(6, 55, 60, 0, 'Vous avez eu unlike de '),
(7, 55, 60, 0, 'Vous avez eu un like de '),
(8, 55, 60, 0, 'Vous avez eu unlike de '),
(9, 55, 60, 0, 'Vous avez eu un like de '),
(10, 55, 60, 0, 'Vous avez eu unlike de '),
(11, 55, 60, 0, 'Vous avez eu un like de '),
(12, 55, 60, 0, 'Vous avez eu unlike de '),
(13, 55, 60, 0, 'Vous avez eu un like de '),
(14, 55, 60, 0, 'Vous avez eu unlike de '),
(15, 55, 60, 0, 'Vous avez eu un like de '),
(16, 55, 60, 0, 'Vous avez eu unlike de '),
(17, 55, 60, 0, 'Vous avez eu un like de '),
(18, 55, 60, 0, 'Vous avez eu unlike de '),
(19, 55, 60, 0, 'Vous avez eu un like de '),
(20, 55, 60, 0, 'Vous avez eu unlike de '),
(21, 55, 60, 0, 'Vous avez eu un like de '),
(22, 55, 60, 0, 'Vous avez eu unlike de '),
(23, 55, 60, 0, 'Vous avez eu un like de '),
(24, 55, 60, 0, 'Vous avez eu unlike de '),
(25, 55, 60, 0, 'Vous avez eu un like de '),
(26, 55, 60, 0, 'Vous avez eu unlike de '),
(27, 55, 60, 0, 'Vous avez eu un like de '),
(28, 55, 60, 0, 'Vous avez eu unlike de '),
(29, 55, 60, 0, 'Vous avez eu un like de '),
(30, 55, 60, 0, 'Vous avez eu unlike de '),
(31, 55, 60, 0, 'Vous avez eu un like de '),
(32, 55, 60, 0, 'Vous avez eu unlike de '),
(33, 55, 60, 0, 'Vous avez eu un like de '),
(34, 55, 60, 0, 'Vous avez eu unlike de '),
(35, 55, 60, 0, 'Vous avez eu un like de '),
(36, 55, 60, 0, 'Vous avez eu unlike de '),
(37, 55, 60, 0, 'Vous avez eu un like de '),
(38, 55, 60, 0, 'Vous avez eu unlike de '),
(39, 55, 60, 0, 'Vous avez eu un like de '),
(40, 55, 60, 0, 'Vous avez eu unlike de '),
(41, 55, 60, 0, 'Vous avez eu un like de '),
(42, 55, 60, 0, 'Vous avez eu unlike de '),
(43, 58, 55, 0, 'Vous avez eu un like de '),
(44, 58, 55, 0, 'Vous avez eu unlike de '),
(45, 55, 60, 0, 'Vous avez eu un like de '),
(46, 55, 60, 0, 'Vous avez eu unlike de '),
(47, 55, 60, 0, 'Vous avez eu un like de '),
(48, 55, 60, 0, 'Vous avez eu unlike de '),
(49, 55, 60, 0, 'Vous avez eu un like de '),
(50, 55, 59, 0, 'Vous avez eu unlike de '),
(51, 55, 59, 0, 'Vous avez eu un like de '),
(52, 57, 59, 1, 'Vous avez eu unlike de '),
(53, 58, 61, 0, 'Vous avez eu un like de '),
(54, 56, 61, 0, 'Vous avez eu un like de '),
(55, 61, 62, 0, 'Vous avez eu un like de '),
(56, 58, 62, 0, 'Vous avez eu un like de '),
(57, 63, 64, 1, 'Vous avez eu un like de '),
(58, 62, 61, 1, 'Vous avez eu un like de '),
(59, 57, 55, 1, 'Vous avez eu unlike de '),
(60, 57, 55, 1, 'Vous avez eu un like de '),
(61, 55, 56, 0, 'Vous avez eu un like de '),
(62, 55, 64, 0, 'Vous avez eu un like de '),
(63, 55, 58, 0, 'Vous avez eu un like de '),
(64, 55, 61, 0, 'Vous avez eu un like de '),
(65, 60, 55, 0, 'Vous avez eu unlike de '),
(66, 60, 55, 0, 'Vous avez eu un like de '),
(67, 55, 60, 0, 'Vous avez eu unlike de '),
(68, 55, 60, 0, 'Vous avez eu un like de '),
(69, 55, 60, 0, 'Vous avez eu unlike de '),
(70, 55, 60, 0, 'Vous avez eu un like de '),
(71, 55, 60, 0, 'Tu n''es plus liké par '),
(72, 55, 60, 0, 'Tu as eu un like de '),
(73, 55, 60, 0, 'Tu n''es plus liké par '),
(74, 55, 60, 0, 'Tu as eu un like de '),
(75, 64, 55, 0, 'Tu as eu un like de '),
(76, 64, 55, 0, 'Tu n''es plus liké par '),
(77, 61, 55, 1, 'Tu as eu un like de ');

-- --------------------------------------------------------

--
-- Structure de la table `pictures`
--

CREATE TABLE `pictures` (
  `id` int(8) NOT NULL,
  `user_id` int(8) NOT NULL,
  `url_pic_1` varchar(255) DEFAULT NULL,
  `url_pic_2` varchar(255) DEFAULT NULL,
  `url_pic_3` varchar(255) DEFAULT NULL,
  `url_pic_4` varchar(255) DEFAULT NULL,
  `url_pic_5` varchar(255) DEFAULT NULL
) ENGINE=InnoDB AUTO_INCREMENT=26 DEFAULT CHARSET=latin1;

--
-- Contenu de la table `pictures`
--

INSERT INTO `pictures` (`id`, `user_id`, `url_pic_1`, `url_pic_2`, `url_pic_3`, `url_pic_4`, `url_pic_5`) VALUES
(13, 52, '/assets/upload/52/kenshin_avatar.png', NULL, NULL, NULL, NULL),
(14, 53, '/assets/upload/53/photo.jpg', '/assets/upload/53/kenshin_avatar.png', '/assets/upload/53/asus_rog-black.jpg', NULL, NULL),
(15, 54, '/assets/upload/54/1378853_10202279688057118_163299908_n.jpg', NULL, NULL, NULL, NULL),
(16, 56, '/assets/upload/56/photo.jpg', '/assets/upload/56/3431c66c52d308d0c85b235d047a7547-dho5w6.jpg', '/assets/upload/56/MTE5NTU2MzE2NDIwOTk4NjY3.jpg', NULL, NULL),
(17, 55, '/assets/upload/55/profil-550px.jpg', '/assets/upload/55/profil.jpg', '/assets/upload/55/DSC04336.JPG', NULL, NULL),
(18, 61, '/assets/upload/61/jim-parsons.jpg', '/assets/upload/61/02-jim-parsons-1.nocrop.w529.h777.jpg', '/assets/upload/61/936full-jim-parsons.jpg', NULL, NULL),
(19, 62, '/assets/upload/62/f9e2935f8d92d8088db6bc39e7b6a841.jpg', '/assets/upload/62/c08ab445407a70fdfd8e24bdd815807e.jpg', '/assets/upload/62/41f6952f5814323bd923cbc624f94b05.jpg', NULL, NULL),
(20, 57, '/assets/upload/57/beutifull-girl-2Versatileautomedia-gallery.jpg', NULL, NULL, NULL, NULL),
(21, 58, '/assets/upload/58/hugh-jackman-transcendental-meditation-practice.jpg', '/assets/upload/58/hugh-jackman-cast-blackbeard-pan.jpg', '/assets/upload/58/Blackbeard.jpg', NULL, NULL),
(22, 59, '/assets/upload/59/mila-kunis-at-jupiter-ascending-premiere-in-los-angeles_1.jpg', '/assets/upload/59/Mila-Kunis-RQHlpJPHZPfm.jpg', '/assets/upload/59/Mila-Kunis.jpg', NULL, NULL),
(23, 60, '/assets/upload/60/36.jpg', '/assets/upload/60/scarlett-johansson-78634.jpg', '/assets/upload/60/scarlett-johansson-78635.jpg', '/assets/upload/60/scarlett-johansson-78638.jpg', NULL),
(24, 63, '/assets/upload/63/d37fff95b22b08ff51a9a453316c7f8e.jpg', '/assets/upload/63/michelle-rodriguez-at-furious-7-premiere-in-hollywood_1.jpg', '/assets/upload/63/85c5fca638f0966ee0fac93695872c18_large.jpeg', NULL, NULL),
(25, 64, '/assets/upload/64/sex-and-city-gay.jpg', '/assets/upload/64/cynthia-nixon11.jpg', '/assets/upload/64/Cynthia-Nixon-Celebhealthy_com.jpg', NULL, NULL);

-- --------------------------------------------------------

--
-- Structure de la table `tags`
--

CREATE TABLE `tags` (
  `user_id` int(8) NOT NULL,
  `barbu` int(8) DEFAULT NULL,
  `geek` int(8) DEFAULT NULL,
  `bio` int(8) DEFAULT NULL,
  `sport` int(8) DEFAULT NULL,
  `id` int(8) NOT NULL
) ENGINE=InnoDB AUTO_INCREMENT=12 DEFAULT CHARSET=latin1;

--
-- Contenu de la table `tags`
--

INSERT INTO `tags` (`user_id`, `barbu`, `geek`, `bio`, `sport`, `id`) VALUES
(55, 1, 1, 0, 1, 1),
(59, 0, 0, 1, 0, 2),
(57, 0, 1, 0, 0, 4),
(56, 0, 0, 1, 1, 5),
(58, 1, 0, 0, 1, 6),
(60, 0, 1, 0, 1, 7),
(61, 0, 1, 1, 0, 8),
(62, 1, 1, 0, 1, 9),
(63, 0, 0, 1, 1, 10),
(64, 0, 0, 1, 0, 11);

-- --------------------------------------------------------

--
-- Structure de la table `users`
--

CREATE TABLE `users` (
  `id` int(8) NOT NULL,
  `first_name` varchar(255) NOT NULL,
  `last_name` varchar(255) NOT NULL,
  `birthday` date NOT NULL,
  `name` varchar(255) NOT NULL,
  `email` varchar(255) NOT NULL,
  `password` varchar(255) NOT NULL,
  `permits` int(8) NOT NULL,
  `interests` int(8) NOT NULL,
  `pictures` int(8) NOT NULL,
  `likes` int(8) NOT NULL,
  `unlikes` int(8) NOT NULL,
  `sex` varchar(255) NOT NULL,
  `action` int(8) NOT NULL,
  `created_at` datetime NOT NULL,
  `pseudo` varchar(255) NOT NULL,
  `like_sex` varchar(255) NOT NULL,
  `story` text NOT NULL,
  `tag` int(8) DEFAULT NULL,
  `reset_password` varchar(255) NOT NULL,
  `token` varchar(255) DEFAULT NULL,
  `lat` float NOT NULL,
  `lon` float NOT NULL,
  `score` int(11) DEFAULT NULL,
  `locate` varchar(255) NOT NULL
) ENGINE=InnoDB AUTO_INCREMENT=65 DEFAULT CHARSET=latin1;

--
-- Contenu de la table `users`
--

INSERT INTO `users` (`id`, `first_name`, `last_name`, `birthday`, `name`, `email`, `password`, `permits`, `interests`, `pictures`, `likes`, `unlikes`, `sex`, `action`, `created_at`, `pseudo`, `like_sex`, `story`, `tag`, `reset_password`, `token`, `lat`, `lon`, `score`, `locate`) VALUES
(55, 'Yohann', 'Larbi', '1986-02-13', 'Yohann Larbi', 'larbi_yohann@hotmail.com', '8521ecb383aa651311a86e4be56591f65978a76be692f07f2119b019fb115ae6', 0, 0, 0, 7, 0, 'Homme', 0, '2016-08-15 19:33:34', 'Himura', 'Bisexuel', 'Lorem ipsum dolor sit amet, consectetur adipiscing elit. Praesent venenatis ante nec nulla varius, ut dignissim mauris ultrices. Maecenas vel nulla vel nibh egestas maximus. In vel dapibus turpis. Maecenas sit amet ante nec nisi vehicula dignissim. Nulla et tellus viverra, rhoncus enim quis, accumsan magna. Nunc eu finibus felis, id malesuada purus. In gravida est a tempus luctus. Nulla eget mauris ac enim luctus sodales. Aliquam accumsan consectetur neque, vestibulum varius nisi rutrum ut. Nulla facilisi. Vestibulum ante ipsum primis in faucibus orci luctus et ultrices posuere cubilia Curae; Integer tristique volutpat enim. Donec tempor neque nisi, eu mollis mauris lacinia vitae.\r\n\r\nNulla in porta lectus, vel rutrum lectus. Praesent eget interdum nulla. Morbi aliquet augue vel ullamcorper feugiat. Sed ipsum turpis, sollicitudin rhoncus ullamcorper a, venenatis ut diam. Vestibulum volutpat libero eget orci sodales accumsan. Nullam vitae elit vitae erat mollis hendrerit. Duis pellentesque libero nunc, vel accumsan magna vulputate ac. In ut rhoncus neque. Cras at mi non purus suscipit vestibulum. Proin lobortis nisl in dui scelerisque dignissim. Nullam tempor nulla lorem. Nulla facilisi. Morbi tortor turpis, pretium et mollis vitae, ultrices vitae dolor. Proin eu varius lectus, consectetur cursus dui. Morbi enim lorem, sodales a lorem a, molestie consequat augue.\r\n\r\nSuspendisse id turpis dui. Nunc malesuada, mi in blandit luctus, ligula ipsum condimentum quam, ac aliquet nunc libero ac lectus. Donec vitae dolor auctor nisi scelerisque ultrices. Nunc ultricies sodales malesuada. Nulla facilisi. Vestibulum ante ipsum primis in faucibus orci luctus et ultrices posuere cubilia Curae; Fusce efficitur elementum arcu. Nunc tortor sapien, commodo at aliquet sit amet, hendrerit sed lacus. Vestibulum in laoreet eros, porta dapibus erat. Duis a consectetur tortor, eu consectetur ipsum. Nulla malesuada libero fermentum massa sagittis, ac maximus mi aliquet. Class aptent taciti sociosqu ad litora torquent per conubia nostra, per inceptos himenaeos. Donec pretium velit a ligula molestie, nec cursus lectus bibendum.\r\n\r\nSed tincidunt massa nec velit fermentum interdum. Morbi velit diam, faucibus vel hendrerit quis, aliquam quis nisi. Maecenas pulvinar viverra eros eu gravida. Phasellus volutpat laoreet ullamcorper. Nulla ligula odio, venenatis nec augue porttitor, molestie feugiat orci. Ut vestibulum a turpis eu pretium. Morbi feugiat dapibus felis, vitae imperdiet lectus dignissim ullamcorper. Donec porta, leo sit amet vehicula scelerisque, nunc libero ullamcorper leo, at sodales nulla nisi ac velit. Ut facilisis enim ut lorem viverra, quis vulputate ex pretium. Nulla id molestie diam, a egestas nisl. Ut massa massa, posuere quis ultrices at, pulvinar nec dolor. Nullam leo sapien, bibendum ut bibendum vitae, placerat rutrum dui. Curabitur turpis purus, gravida id tempor et, rhoncus sed sem.\r\n\r\nInteger hendrerit sed est varius gravida. Maecenas tincidunt tristique blandit. Aenean mi tellus, faucibus sit amet sapien nec, viverra tristique odio. Etiam at tincidunt leo, at pellentesque quam. Quisque at congue nunc, et vulputate nibh. Ut eget elit id lectus maximus posuere. Etiam lacinia orci tellus, et tempor libero ultricies eget. Vestibulum at libero quis massa posuere tristique ac vitae elit. Donec ut velit elementum, imperdiet quam at, ullamcorper quam. Curabitur turpis lacus, bibendum non diam aliquet, commodo dapibus eros. Integer non est velit. Cras consectetur ultrices dolor. Curabitur vel augue quis purus convallis lobortis. Quisque sit amet condimentum diam, eget porttitor elit. Donec sed laoreet mauris. Vivamus at lectus non libero scelerisque pellentesque vel ac augue.', NULL, '', 's%3AXOwWk4aI3pihz2pxfvT_a59Jyl5F8MBM.TgPl3iKWtc8nJupnh6izPPGh%2Fz7%2B%2BCj4WAXpdMk5paI', 48.8781, 2.31386, 5, 'oui'),
(56, 'Bruce', 'Lee', '1956-06-09', 'Bruce Lee', 'bruce@lee.com', 'd9b5f58f0b38198293971865a14074f59eba3e82595becbe86ae51f1d9f1f65e', 0, 0, 0, 3, 0, 'Homme', 0, '2016-08-15 19:34:04', 'Petit Dragon', 'Femme', 'Lorem ipsum dolor sit amet, consectetur adipiscing elit. Praesent venenatis ante nec nulla varius, ut dignissim mauris ultrices. Maecenas vel nulla vel nibh egestas maximus. In vel dapibus turpis. Maecenas sit amet ante nec nisi vehicula dignissim. Nulla et tellus viverra, rhoncus enim quis, accumsan magna. Nunc eu finibus felis, id malesuada purus. In gravida est a tempus luctus. Nulla eget mauris ac enim luctus sodales. Aliquam accumsan consectetur neque, vestibulum varius nisi rutrum ut. Nulla facilisi. Vestibulum ante ipsum primis in faucibus orci luctus et ultrices posuere cubilia Curae; Integer tristique volutpat enim. Donec tempor neque nisi, eu mollis mauris lacinia vitae.\r\n\r\nNulla in porta lectus, vel rutrum lectus. Praesent eget interdum nulla. Morbi aliquet augue vel ullamcorper feugiat. Sed ipsum turpis, sollicitudin rhoncus ullamcorper a, venenatis ut diam. Vestibulum volutpat libero eget orci sodales accumsan. Nullam vitae elit vitae erat mollis hendrerit. Duis pellentesque libero nunc, vel accumsan magna vulputate ac. In ut rhoncus neque. Cras at mi non purus suscipit vestibulum. Proin lobortis nisl in dui scelerisque dignissim. Nullam tempor nulla lorem. Nulla facilisi. Morbi tortor turpis, pretium et mollis vitae, ultrices vitae dolor. Proin eu varius lectus, consectetur cursus dui. Morbi enim lorem, sodales a lorem a, molestie consequat augue.\r\n\r\nSuspendisse id turpis dui. Nunc malesuada, mi in blandit luctus, ligula ipsum condimentum quam, ac aliquet nunc libero ac lectus. Donec vitae dolor auctor nisi scelerisque ultrices. Nunc ultricies sodales malesuada. Nulla facilisi. Vestibulum ante ipsum primis in faucibus orci luctus et ultrices posuere cubilia Curae; Fusce efficitur elementum arcu. Nunc tortor sapien, commodo at aliquet sit amet, hendrerit sed lacus. Vestibulum in laoreet eros, porta dapibus erat. Duis a consectetur tortor, eu consectetur ipsum. Nulla malesuada libero fermentum massa sagittis, ac maximus mi aliquet. Class aptent taciti sociosqu ad litora torquent per conubia nostra, per inceptos himenaeos. Donec pretium velit a ligula molestie, nec cursus lectus bibendum.\r\n\r\nSed tincidunt massa nec velit fermentum interdum. Morbi velit diam, faucibus vel hendrerit quis, aliquam quis nisi. Maecenas pulvinar viverra eros eu gravida. Phasellus volutpat laoreet ullamcorper. Nulla ligula odio, venenatis nec augue porttitor, molestie feugiat orci. Ut vestibulum a turpis eu pretium. Morbi feugiat dapibus felis, vitae imperdiet lectus dignissim ullamcorper. Donec porta, leo sit amet vehicula scelerisque, nunc libero ullamcorper leo, at sodales nulla nisi ac velit. Ut facilisis enim ut lorem viverra, quis vulputate ex pretium. Nulla id molestie diam, a egestas nisl. Ut massa massa, posuere quis ultrices at, pulvinar nec dolor. Nullam leo sapien, bibendum ut bibendum vitae, placerat rutrum dui. Curabitur turpis purus, gravida id tempor et, rhoncus sed sem.\r\n\r\nInteger hendrerit sed est varius gravida. Maecenas tincidunt tristique blandit. Aenean mi tellus, faucibus sit amet sapien nec, viverra tristique odio. Etiam at tincidunt leo, at pellentesque quam. Quisque at congue nunc, et vulputate nibh. Ut eget elit id lectus maximus posuere. Etiam lacinia orci tellus, et tempor libero ultricies eget. Vestibulum at libero quis massa posuere tristique ac vitae elit. Donec ut velit elementum, imperdiet quam at, ullamcorper quam. Curabitur turpis lacus, bibendum non diam aliquet, commodo dapibus eros. Integer non est velit. Cras consectetur ultrices dolor. Curabitur vel augue quis purus convallis lobortis. Quisque sit amet condimentum diam, eget porttitor elit. Donec sed laoreet mauris. Vivamus at lectus non libero scelerisque pellentesque vel ac augue.', NULL, '', 's%3AxuDwvBjRUA3Sl4IvfpmY0ARhUjSi-8x3.y227XUZWfeefUlefCwhoqYzXOYIdHDIzIeX9yQmiZAw', 48.8942, 2.32069, 2, 'oui'),
(57, 'Sarah', 'Call', '1986-07-26', 'Sarah Call', 'sarah@call.com', 'd9b5f58f0b38198293971865a14074f59eba3e82595becbe86ae51f1d9f1f65e', 0, 0, 0, 1, 0, 'Femme', 0, '2016-08-17 17:27:38', 'Dooly', 'Homme', 'Lorem ipsum dolor sit amet, consectetur adipiscing elit. Donec viverra purus vel purus eleifend sollicitudin ut ac quam. Donec consectetur risus vel porta tempus. Sed ut turpis ornare, convallis ligula aliquam, posuere massa. Duis quis ante suscipit lorem elementum cursus. Pellentesque dignissim sed risus ac viverra. Ut luctus cursus viverra. Aenean malesuada ut massa eget finibus. Curabitur efficitur eu odio in ultrices. Nam in augue varius, rutrum lectus sed, vehicula nulla. Praesent lobortis, nisl sit amet convallis laoreet, nisl libero feugiat nisi, ut condimentum nisl nunc quis felis. Nullam finibus dictum neque in feugiat. Ut eu leo nec massa imperdiet porttitor vel ut lacus. Nullam eu nunc consectetur, blandit risus pharetra, interdum tortor. Aenean consequat viverra augue sed eleifend.\r\n\r\nPellentesque viverra nisl eu aliquet sollicitudin. In hac habitasse platea dictumst. Interdum et malesuada fames ac ante ipsum primis in faucibus. Duis dignissim gravida tincidunt. Curabitur tellus orci, laoreet a nulla quis, fringilla commodo dolor. Aliquam erat volutpat. Sed in scelerisque nisi, vitae scelerisque nisi. Vestibulum egestas vel augue et efficitur. Duis nibh orci, commodo a vulputate et, tempus feugiat eros. Sed sed tristique sem. Ut bibendum tellus quis congue malesuada. Suspendisse vel ligula diam. Praesent tristique ornare nisi, nec ullamcorper ipsum vehicula non.\r\n\r\nInteger lacinia augue sed est sodales tristique. Vestibulum ac aliquet eros. Vestibulum a facilisis lectus, in eleifend tortor. Nam lectus diam, blandit id augue non, commodo malesuada elit. Duis in arcu eu erat ultrices sagittis id porta leo. Phasellus pellentesque turpis ac urna iaculis finibus. Donec rutrum a sapien eu pharetra.\r\n\r\nPraesent eget arcu quis augue bibendum congue. Phasellus eleifend, lacus vitae imperdiet ornare, nisl lacus venenatis lectus, at tempus dolor turpis non lectus. Interdum et malesuada fames ac ante ipsum primis in faucibus. Quisque ut dolor ex. Nulla vulputate est interdum, condimentum mauris sit amet, iaculis ipsum. In metus dolor, eleifend eu dolor dictum, consequat vestibulum orci. Proin luctus leo ut interdum ultrices. Morbi hendrerit augue sem, non lacinia ex imperdiet non. Suspendisse laoreet leo nec sapien laoreet imperdiet. Phasellus vestibulum, massa a imperdiet aliquet, massa augue pellentesque orci, eu eleifend turpis mi a augue. Donec dolor nulla, sodales non faucibus sed, pharetra rutrum dolor. Integer maximus elit et venenatis consequat. Class aptent taciti sociosqu ad litora torquent per conubia nostra, per inceptos himenaeos. Suspendisse aliquet erat ut rhoncus iaculis. Donec tempor blandit lobortis.\r\n\r\nSuspendisse hendrerit porta risus, quis condimentum nisl feugiat et. Quisque at tempor erat. Nam euismod sagittis arcu eget volutpat. Pellentesque dolor augue, condimentum in turpis nec, fringilla pellentesque augue. Sed ultricies tincidunt nisl. Ut posuere ultrices condimentum. Donec feugiat nibh eget ultricies malesuada. Praesent sed ornare augue. Nullam risus lectus, viverra maximus convallis ut, tristique imperdiet nunc.', NULL, '', 's%3AG3VGoZ6y3bMPFX6mePfYtjAV3G2nACVG.Bg%2FDGuuLZ6yojtXjqG0mstMfqvaRDNATPLO9IkEM4c0', 48.881, 2.26546, 4, 'oui'),
(58, 'Hugh', 'Jackman', '1968-10-12', 'Hugh Jackman', 'hugh@jackman.com', 'd9b5f58f0b38198293971865a14074f59eba3e82595becbe86ae51f1d9f1f65e', 0, 0, 0, 3, 0, 'Homme', 0, '2016-08-17 17:45:16', 'Wolverine', 'Femme', 'Lorem ipsum dolor sit amet, consectetur adipiscing elit. Donec viverra purus vel purus eleifend sollicitudin ut ac quam. Donec consectetur risus vel porta tempus. Sed ut turpis ornare, convallis ligula aliquam, posuere massa. Duis quis ante suscipit lorem elementum cursus. Pellentesque dignissim sed risus ac viverra. Ut luctus cursus viverra. Aenean malesuada ut massa eget finibus. Curabitur efficitur eu odio in ultrices. Nam in augue varius, rutrum lectus sed, vehicula nulla. Praesent lobortis, nisl sit amet convallis laoreet, nisl libero feugiat nisi, ut condimentum nisl nunc quis felis. Nullam finibus dictum neque in feugiat. Ut eu leo nec massa imperdiet porttitor vel ut lacus. Nullam eu nunc consectetur, blandit risus pharetra, interdum tortor. Aenean consequat viverra augue sed eleifend.\r\n\r\nPellentesque viverra nisl eu aliquet sollicitudin. In hac habitasse platea dictumst. Interdum et malesuada fames ac ante ipsum primis in faucibus. Duis dignissim gravida tincidunt. Curabitur tellus orci, laoreet a nulla quis, fringilla commodo dolor. Aliquam erat volutpat. Sed in scelerisque nisi, vitae scelerisque nisi. Vestibulum egestas vel augue et efficitur. Duis nibh orci, commodo a vulputate et, tempus feugiat eros. Sed sed tristique sem. Ut bibendum tellus quis congue malesuada. Suspendisse vel ligula diam. Praesent tristique ornare nisi, nec ullamcorper ipsum vehicula non.\r\n\r\nInteger lacinia augue sed est sodales tristique. Vestibulum ac aliquet eros. Vestibulum a facilisis lectus, in eleifend tortor. Nam lectus diam, blandit id augue non, commodo malesuada elit. Duis in arcu eu erat ultrices sagittis id porta leo. Phasellus pellentesque turpis ac urna iaculis finibus. Donec rutrum a sapien eu pharetra.\r\n\r\nPraesent eget arcu quis augue bibendum congue. Phasellus eleifend, lacus vitae imperdiet ornare, nisl lacus venenatis lectus, at tempus dolor turpis non lectus. Interdum et malesuada fames ac ante ipsum primis in faucibus. Quisque ut dolor ex. Nulla vulputate est interdum, condimentum mauris sit amet, iaculis ipsum. In metus dolor, eleifend eu dolor dictum, consequat vestibulum orci. Proin luctus leo ut interdum ultrices. Morbi hendrerit augue sem, non lacinia ex imperdiet non. Suspendisse laoreet leo nec sapien laoreet imperdiet. Phasellus vestibulum, massa a imperdiet aliquet, massa augue pellentesque orci, eu eleifend turpis mi a augue. Donec dolor nulla, sodales non faucibus sed, pharetra rutrum dolor. Integer maximus elit et venenatis consequat. Class aptent taciti sociosqu ad litora torquent per conubia nostra, per inceptos himenaeos. Suspendisse aliquet erat ut rhoncus iaculis. Donec tempor blandit lobortis.\r\n\r\nSuspendisse hendrerit porta risus, quis condimentum nisl feugiat et. Quisque at tempor erat. Nam euismod sagittis arcu eget volutpat. Pellentesque dolor augue, condimentum in turpis nec, fringilla pellentesque augue. Sed ultricies tincidunt nisl. Ut posuere ultrices condimentum. Donec feugiat nibh eget ultricies malesuada. Praesent sed ornare augue. Nullam risus lectus, viverra maximus convallis ut, tristique imperdiet nunc.', NULL, '', 's%3AsxXcVdIajVWpxtP_LnbIC1nsSZkBXnf5.9MqFFK9QrNvx46C6fWQiq8TnqeoLzKFBV6aTkpmIfZc', 48.8487, 2.33936, 3, 'oui'),
(59, 'Mila', 'Kunis', '1983-08-14', 'Mila Kunis', 'mila@kunis.com', 'd9b5f58f0b38198293971865a14074f59eba3e82595becbe86ae51f1d9f1f65e', 0, 0, 0, 2, 0, 'Femme', 0, '2016-08-17 17:49:27', 'Kunis', 'Homme', 'Lorem ipsum dolor sit amet, consectetur adipiscing elit. Donec viverra purus vel purus eleifend sollicitudin ut ac quam. Donec consectetur risus vel porta tempus. Sed ut turpis ornare, convallis ligula aliquam, posuere massa. Duis quis ante suscipit lorem elementum cursus. Pellentesque dignissim sed risus ac viverra. Ut luctus cursus viverra. Aenean malesuada ut massa eget finibus. Curabitur efficitur eu odio in ultrices. Nam in augue varius, rutrum lectus sed, vehicula nulla. Praesent lobortis, nisl sit amet convallis laoreet, nisl libero feugiat nisi, ut condimentum nisl nunc quis felis. Nullam finibus dictum neque in feugiat. Ut eu leo nec massa imperdiet porttitor vel ut lacus. Nullam eu nunc consectetur, blandit risus pharetra, interdum tortor. Aenean consequat viverra augue sed eleifend.\r\n\r\nPellentesque viverra nisl eu aliquet sollicitudin. In hac habitasse platea dictumst. Interdum et malesuada fames ac ante ipsum primis in faucibus. Duis dignissim gravida tincidunt. Curabitur tellus orci, laoreet a nulla quis, fringilla commodo dolor. Aliquam erat volutpat. Sed in scelerisque nisi, vitae scelerisque nisi. Vestibulum egestas vel augue et efficitur. Duis nibh orci, commodo a vulputate et, tempus feugiat eros. Sed sed tristique sem. Ut bibendum tellus quis congue malesuada. Suspendisse vel ligula diam. Praesent tristique ornare nisi, nec ullamcorper ipsum vehicula non.\r\n\r\nInteger lacinia augue sed est sodales tristique. Vestibulum ac aliquet eros. Vestibulum a facilisis lectus, in eleifend tortor. Nam lectus diam, blandit id augue non, commodo malesuada elit. Duis in arcu eu erat ultrices sagittis id porta leo. Phasellus pellentesque turpis ac urna iaculis finibus. Donec rutrum a sapien eu pharetra.\r\n\r\nPraesent eget arcu quis augue bibendum congue. Phasellus eleifend, lacus vitae imperdiet ornare, nisl lacus venenatis lectus, at tempus dolor turpis non lectus. Interdum et malesuada fames ac ante ipsum primis in faucibus. Quisque ut dolor ex. Nulla vulputate est interdum, condimentum mauris sit amet, iaculis ipsum. In metus dolor, eleifend eu dolor dictum, consequat vestibulum orci. Proin luctus leo ut interdum ultrices. Morbi hendrerit augue sem, non lacinia ex imperdiet non. Suspendisse laoreet leo nec sapien laoreet imperdiet. Phasellus vestibulum, massa a imperdiet aliquet, massa augue pellentesque orci, eu eleifend turpis mi a augue. Donec dolor nulla, sodales non faucibus sed, pharetra rutrum dolor. Integer maximus elit et venenatis consequat. Class aptent taciti sociosqu ad litora torquent per conubia nostra, per inceptos himenaeos. Suspendisse aliquet erat ut rhoncus iaculis. Donec tempor blandit lobortis.\r\n\r\nSuspendisse hendrerit porta risus, quis condimentum nisl feugiat et. Quisque at tempor erat. Nam euismod sagittis arcu eget volutpat. Pellentesque dolor augue, condimentum in turpis nec, fringilla pellentesque augue. Sed ultricies tincidunt nisl. Ut posuere ultrices condimentum. Donec feugiat nibh eget ultricies malesuada. Praesent sed ornare augue. Nullam risus lectus, viverra maximus convallis ut, tristique imperdiet nunc.', NULL, '', 's%3AAyCqVMnjxSJJ3-x4LzaxQlrJwDk5HZA4.sff3wZPwiEwsC3bnRbTHaB%2BI0IZHP2veRE7Knh24TKY', 48.8919, 2.31878, 5, 'oui'),
(60, 'Scarlett', 'Johansson', '1984-11-22', 'Scarlett Johansson', 'scarlett@johansson.com', 'd9b5f58f0b38198293971865a14074f59eba3e82595becbe86ae51f1d9f1f65e', 0, 0, 0, 2, 0, 'Femme', 0, '2016-08-17 17:54:58', 'Scar', 'Homme', 'Lorem ipsum dolor sit amet, consectetur adipiscing elit. Donec viverra purus vel purus eleifend sollicitudin ut ac quam. Donec consectetur risus vel porta tempus. Sed ut turpis ornare, convallis ligula aliquam, posuere massa. Duis quis ante suscipit lorem elementum cursus. Pellentesque dignissim sed risus ac viverra. Ut luctus cursus viverra. Aenean malesuada ut massa eget finibus. Curabitur efficitur eu odio in ultrices. Nam in augue varius, rutrum lectus sed, vehicula nulla. Praesent lobortis, nisl sit amet convallis laoreet, nisl libero feugiat nisi, ut condimentum nisl nunc quis felis. Nullam finibus dictum neque in feugiat. Ut eu leo nec massa imperdiet porttitor vel ut lacus. Nullam eu nunc consectetur, blandit risus pharetra, interdum tortor. Aenean consequat viverra augue sed eleifend.\r\n\r\nPellentesque viverra nisl eu aliquet sollicitudin. In hac habitasse platea dictumst. Interdum et malesuada fames ac ante ipsum primis in faucibus. Duis dignissim gravida tincidunt. Curabitur tellus orci, laoreet a nulla quis, fringilla commodo dolor. Aliquam erat volutpat. Sed in scelerisque nisi, vitae scelerisque nisi. Vestibulum egestas vel augue et efficitur. Duis nibh orci, commodo a vulputate et, tempus feugiat eros. Sed sed tristique sem. Ut bibendum tellus quis congue malesuada. Suspendisse vel ligula diam. Praesent tristique ornare nisi, nec ullamcorper ipsum vehicula non.\r\n\r\nInteger lacinia augue sed est sodales tristique. Vestibulum ac aliquet eros. Vestibulum a facilisis lectus, in eleifend tortor. Nam lectus diam, blandit id augue non, commodo malesuada elit. Duis in arcu eu erat ultrices sagittis id porta leo. Phasellus pellentesque turpis ac urna iaculis finibus. Donec rutrum a sapien eu pharetra.\r\n\r\nPraesent eget arcu quis augue bibendum congue. Phasellus eleifend, lacus vitae imperdiet ornare, nisl lacus venenatis lectus, at tempus dolor turpis non lectus. Interdum et malesuada fames ac ante ipsum primis in faucibus. Quisque ut dolor ex. Nulla vulputate est interdum, condimentum mauris sit amet, iaculis ipsum. In metus dolor, eleifend eu dolor dictum, consequat vestibulum orci. Proin luctus leo ut interdum ultrices. Morbi hendrerit augue sem, non lacinia ex imperdiet non. Suspendisse laoreet leo nec sapien laoreet imperdiet. Phasellus vestibulum, massa a imperdiet aliquet, massa augue pellentesque orci, eu eleifend turpis mi a augue. Donec dolor nulla, sodales non faucibus sed, pharetra rutrum dolor. Integer maximus elit et venenatis consequat. Class aptent taciti sociosqu ad litora torquent per conubia nostra, per inceptos himenaeos. Suspendisse aliquet erat ut rhoncus iaculis. Donec tempor blandit lobortis.\r\n\r\nSuspendisse hendrerit porta risus, quis condimentum nisl feugiat et. Quisque at tempor erat. Nam euismod sagittis arcu eget volutpat. Pellentesque dolor augue, condimentum in turpis nec, fringilla pellentesque augue. Sed ultricies tincidunt nisl. Ut posuere ultrices condimentum. Donec feugiat nibh eget ultricies malesuada. Praesent sed ornare augue. Nullam risus lectus, viverra maximus convallis ut, tristique imperdiet nunc.', NULL, '', 's%3AYblVvmrc8Ur57iZok2754vs7jhBP71zS.6TbRk1ljD3pthPfV4x8HIdhyqAXtBPzxiUHDp0JyTSE', 48.88, 2.2949, 9, 'oui'),
(61, 'Jim', 'Parsons', '1981-06-05', 'Jim Parsons', 'jim@parsons', 'd9b5f58f0b38198293971865a14074f59eba3e82595becbe86ae51f1d9f1f65e', 0, 0, 0, 2, 0, 'Homme', 0, '2016-08-25 12:41:34', 'Sheldon', 'Homme', 'Dr Sheldon Lee Cooper est un personnage de la série télévisée américaine The Big Bang Theory, diffusée depuis 2007 sur le réseau CBS. Il est joué par l''acteur américain Jim Parsons. Il s''agit d''un physicien théoricien surdoué originaire du Texas qui vit en colocation avec le Dr Leonard Hofstadter dans un appartement au quatrième étage d''un immeuble situé à Pasadena, en Californie. Ses travaux concernent généralement la théorie des cordes. Il a obtenu son premier doctorat à l''âge de 16 ans seulement, est entré à l''université à l''âge de 11 ans et a été le plus jeune à recevoir de nombreux prix de physique. Il a actuellement une maîtrise et deux doctorats1, et obtient également par la suite un diplôme de notaire. Il a un QI de 187 et dispose d''une mémoire eidétique2.', NULL, '', 's%3AKRg44CPL94hnS3IqfZBgD6258a1FsgON.5%2BCzfuM%2FZ3lHR3Zx%2BLbpU22wiF9YGGn8hAOe6vq%2BPi0', 48.8813, 2.38927, 1, 'oui'),
(62, 'Zachary', 'Quinto', '1977-06-02', 'Zachary Quinto', 'zachary@quinto.com', 'd9b5f58f0b38198293971865a14074f59eba3e82595becbe86ae51f1d9f1f65e', 0, 0, 0, 1, 0, 'Homme', 0, '2016-08-25 12:49:42', 'Zacha', 'Homme', 'Zachary Quinto est un acteur et producteur américain, né le 2 juin 1977 à Pittsburgh. Il est notamment connu pour avoir joué le rôle Sylar dans la série Heroes et celui de Spock dans la récente saga Star Trek.', NULL, '', '', 48.8614, 2.36922, 0, 'oui'),
(63, 'Michelle', '', '1978-07-12', 'Michelle Rodriguez', 'michelle@rodriguez', 'd9b5f58f0b38198293971865a14074f59eba3e82595becbe86ae51f1d9f1f65e', 0, 0, 0, 1, 0, 'Femme', 0, '2016-08-25 12:55:40', 'Mich', 'Femme', 'Michelle Rodríguez naît à San Antonio, au Texas, de Rafael et Carmen Rodríguez1. Sa mère, Carmen Milady Rodríguez (née Pared Espinal) est originaire de la République dominicaine, et son père, Rafael Rodríguez, est un Portoricain qui a servi dans l''armée des États-Unis.\r\nÀ l''âge de huit ans, elle déménage avec sa famille en République dominicaine, où elle reste deux ans, avant de s''établir à Porto Rico2. Enfin, à onze ans, elle retourne aux États-Unis avec ses parents qui se fixent à Jersey City dans le New Jersey. Elle fut expulsée de cinq écoles et a étudié brièvement dans une école de commerce avant de la quitter pour poursuivre une carrière d''actrice, avec l''objectif de devenir scénariste et metteur en scène. Elle a dix frères et sœurs, et demi-frères et sœurs.', NULL, '', 's%3AVIoOzG6Kb5aciPprFOHhq_Ya3x4ulVnF.obI%2FGXXFO7eqQDVEtq2qY7Bz%2BG%2BMCy5zH4kYgieRluw', 48.8358, 2.33883, 1, 'non'),
(64, 'Cynthia', 'Nixon', '1966-04-06', 'Cynthia Nixon', 'cynthia@nixon.com', 'd9b5f58f0b38198293971865a14074f59eba3e82595becbe86ae51f1d9f1f65e', 0, 0, 0, 0, 0, 'Femme', 0, '2016-08-25 12:58:42', 'Nixon', 'Bisexuel', 'Elle obtient son premier rôle remarqué au cinéma dans Little Darlings (en) de Ronald F. Maxwell avec entre autres Tatum O''Neal et Matt Dillon.\r\nC''est au théâtre, à Broadway, qu’elle fera un début prometteur puis une carrière variée par les personnages qu’elle portera. Parmi ses participations : The Last Night of Ballyhoo, Angels in America, The Heidi Chronicles, The Women. Son rôle dans The Philadelphia Story lui vaudra un “Theatre World Award” décerné par le Los Angeles Drama Critics à l’âge de 14 ans.', NULL, '', 's%3ASJFb9a10Nv-XqkQVjsFIR4OqIM2TbgtN.dLGT%2BL3kH%2BOHOHVQN0uaQkV%2FOZ4CMrPdxcLvnJqb9Ps', 48.8719, 2.31764, 5, 'non');

-- --------------------------------------------------------

--
-- Structure de la table `views`
--

CREATE TABLE `views` (
  `id` int(11) NOT NULL,
  `user_id` int(11) NOT NULL,
  `user_view` int(11) NOT NULL,
  `created_at` datetime NOT NULL
) ENGINE=InnoDB AUTO_INCREMENT=62 DEFAULT CHARSET=latin1;

--
-- Contenu de la table `views`
--

INSERT INTO `views` (`id`, `user_id`, `user_view`, `created_at`) VALUES
(1, 55, 59, '0000-00-00 00:00:00'),
(2, 55, 63, '0000-00-00 00:00:00'),
(3, 56, 57, '0000-00-00 00:00:00'),
(4, 57, 55, '2016-09-24 14:05:11'),
(5, 60, 55, '2016-09-24 14:05:32'),
(6, 55, 60, '2016-09-24 14:18:51'),
(7, 58, 60, '2016-09-24 14:18:55'),
(8, 55, 60, '2016-09-24 14:19:05'),
(9, 55, 64, '2016-09-24 14:25:54'),
(10, 55, 64, '2016-09-24 14:26:05'),
(11, 55, 60, '2016-09-24 14:26:21'),
(12, 55, 59, '2016-09-24 14:40:44'),
(13, 59, 55, '2016-09-24 14:44:52'),
(14, 60, 55, '2016-09-24 14:44:57'),
(15, 60, 55, '2016-09-24 14:45:49'),
(16, 59, 55, '2016-09-24 14:45:57'),
(17, 59, 55, '2016-09-24 14:46:13'),
(18, 59, 55, '2016-09-24 14:46:30'),
(19, 57, 55, '2016-09-24 14:47:15'),
(20, 59, 55, '2016-09-24 16:12:38'),
(21, 59, 55, '2016-09-24 16:13:55'),
(22, 59, 55, '2016-09-24 16:14:09'),
(23, 60, 55, '2016-09-24 16:14:30'),
(24, 55, 64, '2016-09-24 16:28:33'),
(25, 55, 64, '2016-09-24 16:29:30'),
(26, 55, 64, '2016-09-24 16:30:00'),
(27, 55, 64, '2016-09-24 16:30:16'),
(28, 63, 64, '2016-09-24 16:30:25'),
(29, 56, 64, '2016-09-24 16:30:29'),
(30, 55, 58, '2016-09-24 16:31:05'),
(31, 55, 58, '2016-09-24 16:31:13'),
(32, 55, 58, '2016-09-24 16:31:17'),
(33, 55, 58, '2016-09-24 16:31:20'),
(34, 57, 55, '2016-09-24 16:32:45'),
(35, 58, 55, '2016-09-24 16:32:53'),
(36, 64, 55, '2016-09-24 16:32:56'),
(37, 64, 55, '2016-09-24 16:32:58'),
(38, 64, 55, '2016-09-24 16:33:04'),
(39, 58, 55, '2016-09-24 16:34:17'),
(40, 61, 55, '2016-09-24 16:34:24'),
(41, 59, 55, '2016-09-24 16:34:28'),
(42, 60, 55, '2016-09-24 16:34:30'),
(43, 60, 55, '2016-09-24 16:34:35'),
(44, 59, 55, '2016-09-24 16:34:51'),
(45, 58, 55, '2016-09-24 16:36:14'),
(46, 56, 55, '2016-09-24 16:36:20'),
(47, 59, 55, '2016-09-24 16:36:23'),
(48, 60, 55, '2016-09-24 16:36:26'),
(49, 60, 55, '2016-09-24 16:36:31'),
(50, 60, 55, '2016-09-24 16:36:33'),
(51, 60, 55, '2016-09-24 16:36:39'),
(52, 60, 55, '2016-09-24 16:37:14'),
(53, 60, 55, '2016-09-24 16:37:42'),
(54, 64, 55, '2016-09-24 17:48:56'),
(55, 57, 55, '2016-09-24 17:49:53'),
(56, 64, 56, '2016-09-24 17:52:11'),
(57, 60, 56, '2016-09-24 17:52:15'),
(58, 59, 56, '2016-09-24 17:52:19'),
(59, 57, 56, '2016-09-24 17:52:22'),
(60, 57, 55, '2016-09-24 18:25:04'),
(61, 59, 55, '2016-09-24 18:49:44');

--
-- Index pour les tables exportées
--

--
-- Index pour la table `likes`
--
ALTER TABLE `likes`
  ADD PRIMARY KEY (`id`);

--
-- Index pour la table `messages`
--
ALTER TABLE `messages`
  ADD PRIMARY KEY (`id`);

--
-- Index pour la table `notifications`
--
ALTER TABLE `notifications`
  ADD PRIMARY KEY (`id`),
  ADD UNIQUE KEY `id` (`id`);

--
-- Index pour la table `pictures`
--
ALTER TABLE `pictures`
  ADD PRIMARY KEY (`id`);

--
-- Index pour la table `tags`
--
ALTER TABLE `tags`
  ADD PRIMARY KEY (`id`);

--
-- Index pour la table `users`
--
ALTER TABLE `users`
  ADD PRIMARY KEY (`id`);

--
-- Index pour la table `views`
--
ALTER TABLE `views`
  ADD PRIMARY KEY (`id`);

--
-- AUTO_INCREMENT pour les tables exportées
--

--
-- AUTO_INCREMENT pour la table `likes`
--
ALTER TABLE `likes`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT,AUTO_INCREMENT=66;
--
-- AUTO_INCREMENT pour la table `messages`
--
ALTER TABLE `messages`
  MODIFY `id` int(8) NOT NULL AUTO_INCREMENT,AUTO_INCREMENT=59;
--
-- AUTO_INCREMENT pour la table `notifications`
--
ALTER TABLE `notifications`
  MODIFY `id` int(8) NOT NULL AUTO_INCREMENT,AUTO_INCREMENT=78;
--
-- AUTO_INCREMENT pour la table `pictures`
--
ALTER TABLE `pictures`
  MODIFY `id` int(8) NOT NULL AUTO_INCREMENT,AUTO_INCREMENT=26;
--
-- AUTO_INCREMENT pour la table `tags`
--
ALTER TABLE `tags`
  MODIFY `id` int(8) NOT NULL AUTO_INCREMENT,AUTO_INCREMENT=12;
--
-- AUTO_INCREMENT pour la table `users`
--
ALTER TABLE `users`
  MODIFY `id` int(8) NOT NULL AUTO_INCREMENT,AUTO_INCREMENT=65;
--
-- AUTO_INCREMENT pour la table `views`
--
ALTER TABLE `views`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT,AUTO_INCREMENT=62;
