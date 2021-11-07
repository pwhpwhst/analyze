create database compiler;
use compiler;


create table t_compile_file(
	`id` INT(11) NOT NULL AUTO_INCREMENT,
	`path` VARCHAR(300) NOT NULL,
	`file_name` VARCHAR(50) NOT NULL,
	`status` INT(11) NOT NULL,
	PRIMARY KEY (`id`)
)
COLLATE='utf8_general_ci'
ENGINE=InnoDB
AUTO_INCREMENT=0
;