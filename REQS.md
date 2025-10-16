Virtualios ir realios mašinos realizacija

Užduočiai atlikti reikia realizuoti suprojektuotą virtualią ir realią mašiną, t.y. parašyti klases, modulius, funkcijas (priklauso nuo pasirinktos kalbos), realizuojančias suprojektuotas komponentes.

Jei realizuojant pasirodys, kad reikia dėl vienų ar kitų priežasčių taisyti projektą (kažkas nebuvo numatyta ar pan.), tą galima daryti, tačiau nekeičiant užduoties esmės. Atsiskaitymo metu tuomet reikės parodyti ir paaiškinti atliktus pakeitimus.

Virtualios mašinos projekte turi būti realizuota:
Parašyta bent viena pavyzdinė programa, kurią reiks naudoti pristatant virtualią mašiną atsiskaitymo metu.
Galimybė įvykdyti programą iš karto arba vykdyti ją žingsniniu rėžimu.
Vartotojo sąsajoje turi būti komandų atlikimo demonstracija bei visų VM komponentų būsenų kaita vykdant programą žingsniniu režimu.
Registrų reikšmės.
Sekanti vykdoma komanda.
Išorinių įrenginių būsenos.
Vykdomos komandos VM puslapio reikšmės.
Turi būti galimybė atvaizduoti VM atmintį.
Turi būti galimybė atvaizduoti RM atmintį arba nurodytą RM atminties puslapį.
Puslapiai VM skiriami ne nuosekliai
Papildomų balai skiriami už:
Lankstus vartotojo aplinka (grafinė)
Leistų užkrauti kitas vartotojų programas ir valdymas būtų atiduodamas vėliausiai užkrautajai (jei laisvos atminties nepakanka apie tai pranešama)
Laisvi puslapiai parenkami atsitiktine tvarka
Vartotojo programos vykdymo metu galima pakeisti: registrų būsena, atimtyje esančią informaciją.

Kadangi OS dar nėra, turėtų būti parašyta valdymo programa, kuri atstotų primityvių nemultiprograminų OS: leistų įkelti vieną vartotojo programą ir ją įvykdyti.

Programuojama gali būti bet kuria programavimo kalba. Vartotojo interfeisas gali būti tiek grafinis (GUI), tiek komandinis (CMD). Programos išeities tekstai (source kodas) turi būti tvarkingi, parašyti laikantis struktūrinio (ar objektinio) programavimo reikalavimų.

Užduotį rekomenduojama atlikti etapais. Pradžioje parašykite programą, emuliuojančią VM veikimą, kuri tiesiog įkeltų į atmintį (be jokios puslapių transliacijos) programą ir ją įvykdytų. Tada realizuokite realios mašinos komponentes, jau laikydami, kad virtualaus procesoriaus darbą imituoja realios mašinos procesorius, o virtuali atmintis yra dalis realios mašinos vartotojo atminties.

Atsiskaitymui reikia parašyti kelias nesudėtingas, bet prasmingas programėles jūsų virtualiai mašinai, kurios leistų pademonstruoti visą komandų veikimą. Aišku, realizuota virtuali mašina turi galėti įvykdyti ne tik šias, bet ir bet kokias kitas jai parašytas programas. Atsiskaitymo metu reikės pateikti projektą iš pirmos dalies, parodyti ir paaiškinti programos išeities tekstus (source kodą), pademonstruoti ir paaiškinti jos veikimą, atsakyti į klausimus, susijusius tiek su dalykine sritimi ("kam reikalingas šis procesoriaus registras"), tiek realizacija ("ką daro ši funkcija"). Reikalaujama žinoti tiek dalykinės srities, tiek realizacines sąvokas, mokėti modifikuoti programą, realizuojančią VM, bei programą, parašytą tai VM, paaiškinti atliktų modifikacijų įtaką.
Vertinama tik originali (autoriaus parašyta) programos dalis. Studentas privalo suprasti ir gebėti paaiškinti savo programos (visumoje ir atskirų dalių) veikimą, kitaip tariant paaiškinti, kam reikalingas nurodytam tikslui pasiekti kiekvienas programos kodo fragmentas. Tuo atveju, jeigu studentas nesugebėjo išspręsti kurios nors atskiros užduoties dalies ir pasinaudojo kitų parašytu sprendimu (pvz., nusirašant nuo internetinio šaltinio), studentas privalo tą faktą deklaruoti dėstytojui. Priešingu atveju studento darbas bus laikomas plagiatu ir vertinamas 0 balų, o studento elgesys laikomas nesąžiningu akademinės etikos požiūriu.
Maksimalus balas skiriamas tuo atveju, jeigu:
pateikta programa sėkmingai kompiliuojasi ir vykdoma, kompiuterių klasių programinėje/techninėje aplinkoje;
programos vykdymo rezultatai pilnai atitinka nurodytą specifikaciją (užduoties formulavimą)
studentas geba dirbti su nurodytais programos paruošimo, derinimo ir vykdymo instrumentais, prieinamais kompiuterinėse klasėse;
programos vartotojo sąsaja tvarkinga, aiški, informatyvi, leidžianti vykdyti programą su reikalingais įvesties duomenimis numatytais užduotyje režimais.
studentas sugeba pilnai paaiškinti savo programos (visumoje ir atskirų dalių) veikimą, pagrįsdamas sąsajas su įsisavinta teorine medžiaga.
Maksimalus įvertinimas skiriamas, jei studentas geba
įvertinti naudojamų algoritmų, sudėtingumą,
įvardinti sprendimo panašumus ir skirtumus, privalumus ir trūkumus,
nedidele apimtimi modifikuoti/pritaikyti sprendimą pagal dėstytojo pateiktus reikalavimus.
