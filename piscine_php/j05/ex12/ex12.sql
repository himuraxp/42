SELECT `nom`, `prenom`
FROM `db_ylarbi`.`fiche_personne`
WHERE `nom` REGEXP '(.*)-(.*)'
OR  `prenom` REGEXP '(.*)-(.*)'
ORDER BY `nom` ASC, `prenom` ASC;
