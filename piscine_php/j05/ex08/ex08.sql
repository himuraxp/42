SELECT CONCAT_WS(' ', `nom`, `prenom`, CAST(`date_naissance` AS DATE)) AS 'date de naissance'
 FROM `db_ylarbi`.`fiche_personne`
 WHERE YEAR(`date_naissance`) = '1989'
 ORDER BY `nom` ASC;
