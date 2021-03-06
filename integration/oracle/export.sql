--------------------------------------------------------
--  Fichier cr�� - dimanche-janvier-03-2021   
--------------------------------------------------------
--------------------------------------------------------
--  DDL for Table CF
--------------------------------------------------------

  CREATE TABLE "MALEK1"."CF" 
   (	"CF_ID" VARCHAR2(20 BYTE), 
	"SOLDE" VARCHAR2(20 BYTE), 
	"CIN" VARCHAR2(20 BYTE)
   ) SEGMENT CREATION IMMEDIATE 
  PCTFREE 10 PCTUSED 40 INITRANS 1 MAXTRANS 255 NOCOMPRESS LOGGING
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM" ;
--------------------------------------------------------
--  DDL for Table CLIENT
--------------------------------------------------------

  CREATE TABLE "MALEK1"."CLIENT" 
   (	"CIN" VARCHAR2(20 BYTE), 
	"NAME" VARCHAR2(20 BYTE), 
	"PRENOM" VARCHAR2(20 BYTE), 
	"MAIL" VARCHAR2(20 BYTE), 
	"PHONE" VARCHAR2(20 BYTE), 
	"HBD" VARCHAR2(20 BYTE), 
	"OPERATEUR" VARCHAR2(20 BYTE)
   ) SEGMENT CREATION IMMEDIATE 
  PCTFREE 10 PCTUSED 40 INITRANS 1 MAXTRANS 255 NOCOMPRESS LOGGING
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM" ;
--------------------------------------------------------
--  DDL for Table COMMANDE
--------------------------------------------------------

  CREATE TABLE "MALEK1"."COMMANDE" 
   (	"IDENTIFIANT" NUMBER, 
	"PRODUITS" VARCHAR2(50 BYTE), 
	"DATE_COMMANDE" VARCHAR2(50 BYTE), 
	"MODE_PAIMENT" VARCHAR2(50 BYTE), 
	"MONTANT" VARCHAR2(20 BYTE), 
	"CODE_FOURNISSEUR" NUMBER
   ) SEGMENT CREATION IMMEDIATE 
  PCTFREE 10 PCTUSED 40 INITRANS 1 MAXTRANS 255 NOCOMPRESS LOGGING
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM" ;
--------------------------------------------------------
--  DDL for Table EMPLOYEE
--------------------------------------------------------

  CREATE TABLE "MALEK1"."EMPLOYEE" 
   (	"NOM" VARCHAR2(20 BYTE), 
	"PRENOM" VARCHAR2(20 BYTE), 
	"EMAIL" VARCHAR2(20 BYTE), 
	"ADRESSE" VARCHAR2(20 BYTE), 
	"ID" NUMBER, 
	"CIN" VARCHAR2(20 BYTE), 
	"NUM_TELEPHONE" VARCHAR2(20 BYTE), 
	"SALAIRE" NUMBER, 
	"DATE_NAISSANCE" VARCHAR2(20 BYTE), 
	"DATE_EMBAUCHE" VARCHAR2(20 BYTE), 
	"TYPE_DE_CONTRACT" VARCHAR2(20 BYTE), 
	"OPERATEUR" VARCHAR2(20 BYTE)
   ) SEGMENT CREATION IMMEDIATE 
  PCTFREE 10 PCTUSED 40 INITRANS 1 MAXTRANS 255 NOCOMPRESS LOGGING
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM" ;
--------------------------------------------------------
--  DDL for Table DEMANDE
--------------------------------------------------------

  CREATE TABLE "MALEK1"."DEMANDE" 
   (	"IDENTIFIANT" VARCHAR2(20 BYTE), 
	"DATE_DEBUT" VARCHAR2(20 BYTE), 
	"DATE_FIN" VARCHAR2(20 BYTE), 
	"ETATS" VARCHAR2(20 BYTE) DEFAULT 'en attente', 
	"ID" NUMBER, 
	"TYPE_CONGE" VARCHAR2(20 BYTE)
   ) SEGMENT CREATION IMMEDIATE 
  PCTFREE 10 PCTUSED 40 INITRANS 1 MAXTRANS 255 NOCOMPRESS LOGGING
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM" ;
--------------------------------------------------------
--  DDL for Table FICHE
--------------------------------------------------------

  CREATE TABLE "MALEK1"."FICHE" 
   (	"NUM_MODELE" NUMBER(*,0), 
	"AGE" NUMBER(*,0), 
	"ETAT" VARCHAR2(20 BYTE), 
	"DATE_M" VARCHAR2(20 BYTE), 
	"DESCRIPTION" VARCHAR2(200 BYTE)
   ) SEGMENT CREATION IMMEDIATE 
  PCTFREE 10 PCTUSED 40 INITRANS 1 MAXTRANS 255 NOCOMPRESS LOGGING
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM" ;
--------------------------------------------------------
--  DDL for Table FOURNISSEUR
--------------------------------------------------------

  CREATE TABLE "MALEK1"."FOURNISSEUR" 
   (	"CODE" NUMBER, 
	"NOM" VARCHAR2(20 BYTE), 
	"ADRESSE" VARCHAR2(20 BYTE), 
	"NUM_TEL" NUMBER, 
	"SERVICE" VARCHAR2(20 BYTE), 
	"DEBUT_CONTRAT" VARCHAR2(20 BYTE), 
	"FIN_CONTRAT" VARCHAR2(20 BYTE), 
	"COURRIEL" VARCHAR2(2000 BYTE)
   ) SEGMENT CREATION IMMEDIATE 
  PCTFREE 10 PCTUSED 40 INITRANS 1 MAXTRANS 255 NOCOMPRESS LOGGING
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM" ;
--------------------------------------------------------
--  DDL for Table LOGIN
--------------------------------------------------------

  CREATE TABLE "MALEK1"."LOGIN" 
   (	"USERNAME" VARCHAR2(20 BYTE), 
	"PASSWORD" VARCHAR2(20 BYTE), 
	"ROLE" VARCHAR2(20 BYTE)
   ) SEGMENT CREATION IMMEDIATE 
  PCTFREE 10 PCTUSED 40 INITRANS 1 MAXTRANS 255 NOCOMPRESS LOGGING
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM" ;
--------------------------------------------------------
--  DDL for Table MACHINE
--------------------------------------------------------

  CREATE TABLE "MALEK1"."MACHINE" 
   (	"NUM_SERIE" VARCHAR2(20 BYTE), 
	"CAPACITE_PRODUCTION" NUMBER, 
	"PUISSANCE_MOTEUR" NUMBER, 
	"NB_HEURE" VARCHAR2(20 BYTE)
   ) SEGMENT CREATION IMMEDIATE 
  PCTFREE 10 PCTUSED 40 INITRANS 1 MAXTRANS 255 NOCOMPRESS LOGGING
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM" ;
--------------------------------------------------------
--  DDL for Table MACHINE_FICHE
--------------------------------------------------------

  CREATE TABLE "MALEK1"."MACHINE_FICHE" 
   (	"NUM_MODELE_FICHE" NUMBER(*,0), 
	"NUM_SERIE_MACHINE" VARCHAR2(20 BYTE)
   ) SEGMENT CREATION IMMEDIATE 
  PCTFREE 10 PCTUSED 40 INITRANS 1 MAXTRANS 255 NOCOMPRESS LOGGING
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM" ;
REM INSERTING into MALEK1.CF
SET DEFINE OFF;
Insert into MALEK1.CF (CF_ID,SOLDE,CIN) values ('ss92C31a','0','02345678');
Insert into MALEK1.CF (CF_ID,SOLDE,CIN) values ('2kB7fZp5','0','12345678');
REM INSERTING into MALEK1.CLIENT
SET DEFINE OFF;
Insert into MALEK1.CLIENT (CIN,NAME,PRENOM,MAIL,PHONE,HBD,OPERATEUR) values ('02345678','hhhh','bbbb','hjl@hj','53456789','01/01/2002','Orange');
Insert into MALEK1.CLIENT (CIN,NAME,PRENOM,MAIL,PHONE,HBD,OPERATEUR) values ('12345678','hhhhh','bbbbb','hj@hh','51234567','01/01/2002','Orange');
REM INSERTING into MALEK1.COMMANDE
SET DEFINE OFF;
Insert into MALEK1.COMMANDE (IDENTIFIANT,PRODUITS,DATE_COMMANDE,MODE_PAIMENT,MONTANT,CODE_FOURNISSEUR) values ('4532','matieres premieres','01/01/00','cheque','4586325','256');
Insert into MALEK1.COMMANDE (IDENTIFIANT,PRODUITS,DATE_COMMANDE,MODE_PAIMENT,MONTANT,CODE_FOURNISSEUR) values ('1002','matieres premieres','01/01/00','cheque','2000','452');
REM INSERTING into MALEK1.EMPLOYEE
SET DEFINE OFF;
Insert into MALEK1.EMPLOYEE (NOM,PRENOM,EMAIL,ADRESSE,ID,CIN,NUM_TELEPHONE,SALAIRE,DATE_NAISSANCE,DATE_EMBAUCHE,TYPE_DE_CONTRACT,OPERATEUR) values ('gfhjbn','nahd','vbjn@hh','vhjkl','124455','41325255','41326584','4152','fvbn','jjj','CUI',null);
Insert into MALEK1.EMPLOYEE (NOM,PRENOM,EMAIL,ADRESSE,ID,CIN,NUM_TELEPHONE,SALAIRE,DATE_NAISSANCE,DATE_EMBAUCHE,TYPE_DE_CONTRACT,OPERATEUR) values ('gfhjbn','gvbhjn','vbjn@hh','vhjkl','452358','41325255','41326584','4152','fvbn','jjj','CUI',null);
Insert into MALEK1.EMPLOYEE (NOM,PRENOM,EMAIL,ADRESSE,ID,CIN,NUM_TELEPHONE,SALAIRE,DATE_NAISSANCE,DATE_EMBAUCHE,TYPE_DE_CONTRACT,OPERATEUR) values ('fghj','nahd','vbjn@hh','vhjkl','200000','41325255','52555555','4152','fvbn','jjj','CUI','Orange');
Insert into MALEK1.EMPLOYEE (NOM,PRENOM,EMAIL,ADRESSE,ID,CIN,NUM_TELEPHONE,SALAIRE,DATE_NAISSANCE,DATE_EMBAUCHE,TYPE_DE_CONTRACT,OPERATEUR) values ('fghj','nahd','vbjn@hh','vhjkl','166666','41325255','25888888','4152','fvbn','jjj','CUI','Ooredoo');
REM INSERTING into MALEK1.DEMANDE
SET DEFINE OFF;
Insert into MALEK1.DEMANDE (IDENTIFIANT,DATE_DEBUT,DATE_FIN,ETATS,ID,TYPE_CONGE) values ('111111','jk','nhhhhh','en attente','200000','vacances');
Insert into MALEK1.DEMANDE (IDENTIFIANT,DATE_DEBUT,DATE_FIN,ETATS,ID,TYPE_CONGE) values ('123333','jk','bn,','en attente','124455','vacances');
REM INSERTING into MALEK1.FICHE
SET DEFINE OFF;
Insert into MALEK1.FICHE (NUM_MODELE,AGE,ETAT,DATE_M,DESCRIPTION) values ('205','20','Bon etat','01/01/2000','fgghj');
Insert into MALEK1.FICHE (NUM_MODELE,AGE,ETAT,DATE_M,DESCRIPTION) values ('102','10','Bon etat','01/01/2000','neuuf');
Insert into MALEK1.FICHE (NUM_MODELE,AGE,ETAT,DATE_M,DESCRIPTION) values ('236','5','ne fonctionne plus','01/01/2000','cfd');
Insert into MALEK1.FICHE (NUM_MODELE,AGE,ETAT,DATE_M,DESCRIPTION) values ('256','20','Bon etat','01/01/2000','neuf');
Insert into MALEK1.FICHE (NUM_MODELE,AGE,ETAT,DATE_M,DESCRIPTION) values ('2365','5','ne fonctionne plus','01/01/2000','cfdcd');
Insert into MALEK1.FICHE (NUM_MODELE,AGE,ETAT,DATE_M,DESCRIPTION) values ('2000','20','Bon etat','01/01/2000','neuf');
Insert into MALEK1.FICHE (NUM_MODELE,AGE,ETAT,DATE_M,DESCRIPTION) values ('500','20','Bon etat','01/01/2000','ghjk');
Insert into MALEK1.FICHE (NUM_MODELE,AGE,ETAT,DATE_M,DESCRIPTION) values ('1259','20','Bon etat','01/01/2000','hjkl');
Insert into MALEK1.FICHE (NUM_MODELE,AGE,ETAT,DATE_M,DESCRIPTION) values ('5000','5','ne fonctionne plus','01/01/2000','neuf');
Insert into MALEK1.FICHE (NUM_MODELE,AGE,ETAT,DATE_M,DESCRIPTION) values ('233','20','Bon etat','01/01/2000','fhgbn');
Insert into MALEK1.FICHE (NUM_MODELE,AGE,ETAT,DATE_M,DESCRIPTION) values ('900','10','Bon etat','01/01/2000','fgh');
REM INSERTING into MALEK1.FOURNISSEUR
SET DEFINE OFF;
Insert into MALEK1.FOURNISSEUR (CODE,NOM,ADRESSE,NUM_TEL,SERVICE,DEBUT_CONTRAT,FIN_CONTRAT,COURRIEL) values ('256','omayma','gfd','256','matieres premieres','01/01/00','01/01/00','ikhsndcw');
Insert into MALEK1.FOURNISSEUR (CODE,NOM,ADRESSE,NUM_TEL,SERVICE,DEBUT_CONTRAT,FIN_CONTRAT,COURRIEL) values ('256556','zeineb','fghbj','412','matieres premieres','01/01/00','01/01/00','gyhj');
Insert into MALEK1.FOURNISSEUR (CODE,NOM,ADRESSE,NUM_TEL,SERVICE,DEBUT_CONTRAT,FIN_CONTRAT,COURRIEL) values ('452','fgh','ghj','452','matieres premieres','01/01/00','01/01/00','fghj');
REM INSERTING into MALEK1.LOGIN
SET DEFINE OFF;
Insert into MALEK1.LOGIN (USERNAME,PASSWORD,ROLE) values ('malek','elfekih','machine');
Insert into MALEK1.LOGIN (USERNAME,PASSWORD,ROLE) values ('omayma','djebeli','fournisseur');
Insert into MALEK1.LOGIN (USERNAME,PASSWORD,ROLE) values ('nahed','benkacem','employee');
Insert into MALEK1.LOGIN (USERNAME,PASSWORD,ROLE) values ('dhia','benameur','client');
REM INSERTING into MALEK1.MACHINE
SET DEFINE OFF;
Insert into MALEK1.MACHINE (NUM_SERIE,CAPACITE_PRODUCTION,PUISSANCE_MOTEUR,NB_HEURE) values ('ma15','520','8520','230');
Insert into MALEK1.MACHINE (NUM_SERIE,CAPACITE_PRODUCTION,PUISSANCE_MOTEUR,NB_HEURE) values ('FGG152','500','5000','20');
Insert into MALEK1.MACHINE (NUM_SERIE,CAPACITE_PRODUCTION,PUISSANCE_MOTEUR,NB_HEURE) values ('MHJ255','500','2000','20');
Insert into MALEK1.MACHINE (NUM_SERIE,CAPACITE_PRODUCTION,PUISSANCE_MOTEUR,NB_HEURE) values ('LFK256','520','8520','20');
Insert into MALEK1.MACHINE (NUM_SERIE,CAPACITE_PRODUCTION,PUISSANCE_MOTEUR,NB_HEURE) values ('GHJ54','250','8000','10');
Insert into MALEK1.MACHINE (NUM_SERIE,CAPACITE_PRODUCTION,PUISSANCE_MOTEUR,NB_HEURE) values ('NBV20','2000','100','10');
REM INSERTING into MALEK1.MACHINE_FICHE
SET DEFINE OFF;
Insert into MALEK1.MACHINE_FICHE (NUM_MODELE_FICHE,NUM_SERIE_MACHINE) values ('102','LFK256');
Insert into MALEK1.MACHINE_FICHE (NUM_MODELE_FICHE,NUM_SERIE_MACHINE) values ('205','FGG152');
Insert into MALEK1.MACHINE_FICHE (NUM_MODELE_FICHE,NUM_SERIE_MACHINE) values ('256','FGG152');
Insert into MALEK1.MACHINE_FICHE (NUM_MODELE_FICHE,NUM_SERIE_MACHINE) values ('2365','FGG152');
--------------------------------------------------------
--  DDL for Index CF_PK
--------------------------------------------------------

  CREATE UNIQUE INDEX "MALEK1"."CF_PK" ON "MALEK1"."CF" ("CF_ID") 
  PCTFREE 10 INITRANS 2 MAXTRANS 255 COMPUTE STATISTICS 
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM" ;
--------------------------------------------------------
--  DDL for Index CLIENT_PK
--------------------------------------------------------

  CREATE UNIQUE INDEX "MALEK1"."CLIENT_PK" ON "MALEK1"."CLIENT" ("CIN") 
  PCTFREE 10 INITRANS 2 MAXTRANS 255 COMPUTE STATISTICS 
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM" ;
--------------------------------------------------------
--  DDL for Index COMMANDE_PK
--------------------------------------------------------

  CREATE UNIQUE INDEX "MALEK1"."COMMANDE_PK" ON "MALEK1"."COMMANDE" ("IDENTIFIANT") 
  PCTFREE 10 INITRANS 2 MAXTRANS 255 COMPUTE STATISTICS 
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM" ;
--------------------------------------------------------
--  DDL for Index EMPLOYEE_PK
--------------------------------------------------------

  CREATE UNIQUE INDEX "MALEK1"."EMPLOYEE_PK" ON "MALEK1"."EMPLOYEE" ("ID") 
  PCTFREE 10 INITRANS 2 MAXTRANS 255 COMPUTE STATISTICS 
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM" ;
--------------------------------------------------------
--  DDL for Index DEMANDE_PK
--------------------------------------------------------

  CREATE UNIQUE INDEX "MALEK1"."DEMANDE_PK" ON "MALEK1"."DEMANDE" ("IDENTIFIANT") 
  PCTFREE 10 INITRANS 2 MAXTRANS 255 COMPUTE STATISTICS 
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM" ;
--------------------------------------------------------
--  DDL for Index FICHE_PK
--------------------------------------------------------

  CREATE UNIQUE INDEX "MALEK1"."FICHE_PK" ON "MALEK1"."FICHE" ("NUM_MODELE") 
  PCTFREE 10 INITRANS 2 MAXTRANS 255 COMPUTE STATISTICS 
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM" ;
--------------------------------------------------------
--  DDL for Index FOURNISSEUR_PK
--------------------------------------------------------

  CREATE UNIQUE INDEX "MALEK1"."FOURNISSEUR_PK" ON "MALEK1"."FOURNISSEUR" ("CODE") 
  PCTFREE 10 INITRANS 2 MAXTRANS 255 COMPUTE STATISTICS 
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM" ;
--------------------------------------------------------
--  DDL for Index MACHINE_PK
--------------------------------------------------------

  CREATE UNIQUE INDEX "MALEK1"."MACHINE_PK" ON "MALEK1"."MACHINE" ("NUM_SERIE") 
  PCTFREE 10 INITRANS 2 MAXTRANS 255 COMPUTE STATISTICS 
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM" ;
--------------------------------------------------------
--  DDL for Index SYS_C007243
--------------------------------------------------------

  CREATE UNIQUE INDEX "MALEK1"."SYS_C007243" ON "MALEK1"."MACHINE_FICHE" ("NUM_MODELE_FICHE") 
  PCTFREE 10 INITRANS 2 MAXTRANS 255 COMPUTE STATISTICS 
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM" ;
--------------------------------------------------------
--  Constraints for Table CF
--------------------------------------------------------

  ALTER TABLE "MALEK1"."CF" ADD CONSTRAINT "CF_PK" PRIMARY KEY ("CF_ID")
  USING INDEX PCTFREE 10 INITRANS 2 MAXTRANS 255 COMPUTE STATISTICS 
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM"  ENABLE;
  ALTER TABLE "MALEK1"."CF" MODIFY ("CF_ID" NOT NULL ENABLE);
--------------------------------------------------------
--  Constraints for Table CLIENT
--------------------------------------------------------

  ALTER TABLE "MALEK1"."CLIENT" ADD CONSTRAINT "CLIENT_PK" PRIMARY KEY ("CIN")
  USING INDEX PCTFREE 10 INITRANS 2 MAXTRANS 255 COMPUTE STATISTICS 
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM"  ENABLE;
  ALTER TABLE "MALEK1"."CLIENT" MODIFY ("CIN" NOT NULL ENABLE);
--------------------------------------------------------
--  Constraints for Table COMMANDE
--------------------------------------------------------

  ALTER TABLE "MALEK1"."COMMANDE" ADD CONSTRAINT "COMMANDE_PK" PRIMARY KEY ("IDENTIFIANT")
  USING INDEX PCTFREE 10 INITRANS 2 MAXTRANS 255 COMPUTE STATISTICS 
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM"  ENABLE;
  ALTER TABLE "MALEK1"."COMMANDE" MODIFY ("IDENTIFIANT" NOT NULL ENABLE);
--------------------------------------------------------
--  Constraints for Table EMPLOYEE
--------------------------------------------------------

  ALTER TABLE "MALEK1"."EMPLOYEE" ADD CONSTRAINT "EMPLOYEE_PK" PRIMARY KEY ("ID")
  USING INDEX PCTFREE 10 INITRANS 2 MAXTRANS 255 COMPUTE STATISTICS 
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM"  ENABLE;
  ALTER TABLE "MALEK1"."EMPLOYEE" MODIFY ("ID" NOT NULL ENABLE);
--------------------------------------------------------
--  Constraints for Table DEMANDE
--------------------------------------------------------

  ALTER TABLE "MALEK1"."DEMANDE" ADD CONSTRAINT "DEMANDE_PK" PRIMARY KEY ("IDENTIFIANT")
  USING INDEX PCTFREE 10 INITRANS 2 MAXTRANS 255 COMPUTE STATISTICS 
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM"  ENABLE;
  ALTER TABLE "MALEK1"."DEMANDE" MODIFY ("IDENTIFIANT" NOT NULL ENABLE);
--------------------------------------------------------
--  Constraints for Table FICHE
--------------------------------------------------------

  ALTER TABLE "MALEK1"."FICHE" MODIFY ("ETAT" NOT NULL ENABLE);
  ALTER TABLE "MALEK1"."FICHE" MODIFY ("AGE" NOT NULL ENABLE);
  ALTER TABLE "MALEK1"."FICHE" MODIFY ("NUM_MODELE" NOT NULL ENABLE);
  ALTER TABLE "MALEK1"."FICHE" ADD CONSTRAINT "FICHE_PK" PRIMARY KEY ("NUM_MODELE")
  USING INDEX PCTFREE 10 INITRANS 2 MAXTRANS 255 COMPUTE STATISTICS 
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM"  ENABLE;
--------------------------------------------------------
--  Constraints for Table FOURNISSEUR
--------------------------------------------------------

  ALTER TABLE "MALEK1"."FOURNISSEUR" ADD CONSTRAINT "FOURNISSEUR_PK" PRIMARY KEY ("CODE")
  USING INDEX PCTFREE 10 INITRANS 2 MAXTRANS 255 COMPUTE STATISTICS 
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM"  ENABLE;
  ALTER TABLE "MALEK1"."FOURNISSEUR" MODIFY ("CODE" NOT NULL ENABLE);
--------------------------------------------------------
--  Constraints for Table MACHINE
--------------------------------------------------------

  ALTER TABLE "MALEK1"."MACHINE" ADD CONSTRAINT "MACHINE_PK" PRIMARY KEY ("NUM_SERIE")
  USING INDEX PCTFREE 10 INITRANS 2 MAXTRANS 255 COMPUTE STATISTICS 
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM"  ENABLE;
  ALTER TABLE "MALEK1"."MACHINE" MODIFY ("NUM_SERIE" NOT NULL ENABLE);
--------------------------------------------------------
--  Constraints for Table MACHINE_FICHE
--------------------------------------------------------

  ALTER TABLE "MALEK1"."MACHINE_FICHE" ADD UNIQUE ("NUM_MODELE_FICHE")
  USING INDEX PCTFREE 10 INITRANS 2 MAXTRANS 255 COMPUTE STATISTICS 
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM"  ENABLE;
  ALTER TABLE "MALEK1"."MACHINE_FICHE" MODIFY ("NUM_SERIE_MACHINE" NOT NULL ENABLE);
  ALTER TABLE "MALEK1"."MACHINE_FICHE" MODIFY ("NUM_MODELE_FICHE" NOT NULL ENABLE);
--------------------------------------------------------
--  Ref Constraints for Table CF
--------------------------------------------------------

  ALTER TABLE "MALEK1"."CF" ADD CONSTRAINT "PK_CIN" FOREIGN KEY ("CIN")
	  REFERENCES "MALEK1"."CLIENT" ("CIN") ENABLE;
--------------------------------------------------------
--  Ref Constraints for Table COMMANDE
--------------------------------------------------------

  ALTER TABLE "MALEK1"."COMMANDE" ADD CONSTRAINT "FK_CODE" FOREIGN KEY ("CODE_FOURNISSEUR")
	  REFERENCES "MALEK1"."FOURNISSEUR" ("CODE") ENABLE;
--------------------------------------------------------
--  Ref Constraints for Table DEMANDE
--------------------------------------------------------

  ALTER TABLE "MALEK1"."DEMANDE" ADD CONSTRAINT "FK_ID_" FOREIGN KEY ("ID")
	  REFERENCES "MALEK1"."EMPLOYEE" ("ID") ENABLE;
--------------------------------------------------------
--  Ref Constraints for Table MACHINE_FICHE
--------------------------------------------------------

  ALTER TABLE "MALEK1"."MACHINE_FICHE" ADD CONSTRAINT "PK_MODELE" FOREIGN KEY ("NUM_MODELE_FICHE")
	  REFERENCES "MALEK1"."FICHE" ("NUM_MODELE") ENABLE;
  ALTER TABLE "MALEK1"."MACHINE_FICHE" ADD CONSTRAINT "PK_SERIE" FOREIGN KEY ("NUM_SERIE_MACHINE")
	  REFERENCES "MALEK1"."MACHINE" ("NUM_SERIE") ENABLE;
