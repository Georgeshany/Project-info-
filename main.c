#include <stdio.h>  // Bibliothèque principale.
#include <string.h> // Permet d'utiliser principalement la fonction strcmp.
#include <stdlib.h>
#include <unistd.h> // Juste pour le loading du programme.
#include <ctype.h>  // Sert à la fonction tolower, pour accepter les entrées en majuscules, sécuriser les scanf.
#include <math.h>
#include <limits.h>


#define MAX_SIZE 100000
#define MAX_FILE_NAME 200
#define MAX_PRODUITS 100000
#define MAX_NAME_LENGTH 1000
#define MAX_TYP_LENGTH 1000
#define UNITMAX 700


// Définition de la structure pour stocker les informations d'un profil.
typedef struct {
 
  char nom[MAX_SIZE];
  char prenom[MAX_SIZE];
  int numprofile;
  int ref;
  char purchase1 [MAX_SIZE];
  char purchase2 [MAX_SIZE];
  char purchase3 [MAX_SIZE];


} Profile;


typedef struct {
  
  int ref; 
  int quantity1;
  int quantity2;
  int quantity3;
  int reference;
  float price1; 
  float price2;
  float price3;
  char nom[MAX_SIZE];
  char typ[MAX_SIZE];


   
} Produit;
    

  int variabletest;

// Fonction pour déterminer si l'utilisateur est un employé ou un client, fonction principale du programme !
void EmployeeOrClient() {


  
  char type[MAX_SIZE]; 
  char client[MAX_SIZE];
  int mdp;
  double numprofile;
  double lineCount = countline(); 
  numprofile = ((lineCount +89)*21 +17) ;

 int variabletest;


  // Pour chercher le prenom d'un client
  FILE *fichier_clients;
  char line[100];
  int variableFound = 0;
  
  printf("Welcome to \033[1;36m *Semora Store* \033[1;0m !\U0001F600\n"); // Affiche bienvenue suivie de la marque de l'enseigne.
  printf("\n"); // Esapce pour améliorer l'interface.
  // Demande à l'utilisateur s'il est un employé ou un client.
  printf("Are you an employee or a client ?\n\n"); 
  scanf("%s", type); // Récupère la réponse type.

  // Convertit la chaîne de caractères en minuscules pour faciliter la comparaison.
  for (int i = 0; type[i]; i++){ 
    type[i] = tolower(type[i]); 
  }

  // Si l'utilisateur est un employé.
  if (strcmp(type, "employee") == 0) {
    printf("Type in the password :\n"); // Demande à l'utilisateur de saisir le mot de passe.
    
    //  While relié à la fonction clear buffer permettant de sécuriser les scanf.
  while (scanf("%d", &mdp) != 1) {  // Récupère la réponse du mdp.
    clearBuffer();
    printf("Incorrect password\n");
    printf("Please insert password \n");
  }

    // Vérifie si le mot de passe est correct.
    if (mdp == 1234) {
      printf("\n"); // Esapce pour améliorer l'interface.
      printf("Your password is correct, access granted !\n"); // Affiche donc que le mot de passe est correct.
      switchcase (); // Fonction qui amène aux options employee.
    }
    
    // Si le mot de passe est incorrect.
    else {
      printf("\n");
      printf("Invalid password, please try again or log in as a client \n"); // Affiche que le mot de passe est incorrect.
      printf("\n"); // Espace pour améliorer l'interface.
      EmployeeOrClient(); // Recommence le programme au début.
    }
  } 
  
  // Si l'utilisateur est un client.
  else if (strcmp(type, "client") == 0 ) {
    printf("Are you a new client?\n"); // Demande à l'utilisateur si il est nouveau client ou non.
    scanf(" %s", client ); // Récupère la réponse client.
    
    // Convertit la chaîne de caractères en minuscules pour faciliter la comparaison.
    for (int i = 0; client[i]; i++){
    client[i] = tolower(client[i]);
  }

    // Si l'utilisateur est un nouveau client
    if (strcmp(client, "yes") == 0) {
      Profile nouveau_client; // Amène le typedef struct Profile, pour un nouveau client.
      nouveau_client.numprofile = numprofile;
      numprofile = nouveau_client.numprofile;
      printf("\n"); // Esapce pour améliorer l'interface.
      printf("Familly name : "); // Pour que l'utilisateur écrive son nom de famille.
      
      // Do, demander le nom ..
      do {
      
        scanf("%s", nouveau_client.nom); // Récupère la réponse du nom de famille relié au typedef struct profile pour un nouveau client.
    for (int i = 0; nouveau_client.nom[i]; i++){ 
    nouveau_client.nom[i] = tolower(nouveau_client.nom[i]); 
  }
        // Si la valeur est inférieur à 3 alors
        if (strlen(nouveau_client.nom) < 3) {
          printf("Please insert at least 3 letters \n"); // Demande à l'utilisateur d'utiliser 3 lettres minimum.
          printf("- Family name : "); // Redemande le nom de famille.
    }

          // Tant que la valeur entrée est < à 3.
      } while (strlen(nouveau_client.nom) < 3);
       
      printf("First name: "); // Pour que l'utilisateur écrive son prénom.

            // Do, demander le nom ..
      do {
        scanf("%s", nouveau_client.prenom); // Récupère la réponse du nom de famille relié au typedef struct profile pour un nouveau client.
    for (int i = 0; nouveau_client.prenom[i]; i++){ 
    nouveau_client.prenom[i] = tolower(nouveau_client.prenom[i]); 
  }
        // Si la valeur est inférieur à 3 alors
        if (strlen(nouveau_client.prenom) < 3) {
          printf("Please insert at least 3 letters\n"); // Demande à l'utilisateur d'utiliser 3 lettres minimum.
          printf("- First Name : "); // Redemande le nom de famille.
        }

          // Tant que la valeur entrée est < à 3.
      } while (strlen(nouveau_client.prenom) < 3);
      
      printf("Your client number is : %d", nouveau_client.numprofile);
      printf("\n"); // Esapce pour améliorer l'interface.
      printf("\n"); // Esapce pour améliorer l'interface.
      
      //nouveau_client[countline()-1].lineCount==lineCount; 
      
      printf("Profile has been created for %s %s %d.\n", nouveau_client.nom, nouveau_client.prenom, nouveau_client.numprofile); // Affiche que le nom de famille et le prénom ont bien été pris en compte en les ré-affichant.

      // Ouverture du fichier en mode écriture.
      FILE *fichier_clients = fopen("clients.txt", "a");


      strcpy(nouveau_client.purchase1, "NULL1");
      strcpy(nouveau_client.purchase2, "NULL2");
      strcpy(nouveau_client.purchase3, "NULL3");
      
      // Si le fichier s'ouvre bien..
      if (fichier_clients != NULL) {
        // Écriture du nom et du prénom dans le fichier.
        fprintf(fichier_clients, "%s %s %d %s %s %s \n", nouveau_client.prenom, nouveau_client.nom, nouveau_client.numprofile, nouveau_client.purchase1, nouveau_client.purchase2, nouveau_client.purchase3); // Enregistre le nom de famille et le prénom de l'utilisateur pris compte avant.
        fclose(fichier_clients); // Fermeture du fichier.
        switchcase2 (); // Fonction qui amène aux options clients.
        variabletest = 0;
        
        variabletest = nouveau_client.numprofile;
      }

      // Si le fichier ne s'ouvre pas bien..  
      else {
        printf("Error opening file clients.txt has occurred \n"); // Msg d'erreur si le fichier ne s'ouvre pas.
      }
    } 
    
    // Si l'utilisateur, le client est déjà connu.
    else if (strcmp(client, "no") == 0) {
      Profile client_exist; // Amène le typedef struct client, pour les client existants.
      printf("\n"); // Esapce pour améliorer l'interface.
     
      printf("Do you want to log in with your name or ID (enter name or ID)\n");
      char answer [MAX_SIZE];
      scanf("%s", answer);
      
      for (int i = 0; answer[i]; i++){
        answer[i] = tolower(answer[i]);
      }

      //
      if (strcmp(answer, "name") == 0 ) {
         SearchName ();
      }

      //
      else if (strcmp(answer, "number") == 0 || strcmp(answer, "id") == 0 ) {
        printf("\n");
        searchref();
      }

      //
      else {
        printf("Try using the following spelling 'name' or 'ID' \n");
        EmployeeOrClient(); 
      }
    }

    // Si mauvaise réponse.
    else {
      printf("\n"); // Esapce pour améliorer l'interface.
      printf("Try again with the following spelling 'yes' or 'no'.\n"); // Dit à l'utilisateur de réessayer avec le bon orthographe.
      EmployeeOrClient(); // Amène la fonction qui redémarre le programme au début.
    }
  }

  // Sinon si l'utiliseur rentre stop ou quit ou exit.
  else if (strcmp(type, "pots") == 0 || strcmp(type, "tiuq") == 0 ||strcmp(type, "tixe") == 0) {
    stopProgram() ;
  }

  // Si mauvaise réponse.
  else {
    printf("\n"); // Esapce pour améliorer l'interface.
    printf("Try again while using the followings: 'employee' or 'client'.\n"); // Dit à l'utilisateur de réessayer avec le bon orthographe.
    printf("\n"); // Espace pour améliorer l'interface.
    EmployeeOrClient(); // Amène la fonction qui redémarre le programme au début. 
  }
}
















// Fonction qui demande si l'utilisateur veut relancer le programme au choix des options dans le switch case 1 dédié aux employee.
int RestartChoice () {
  
  char restart[MAX_SIZE];
  
  printf("\n"); // Esapce pour améliorer l'interface.
  printf("Would you like to do something else ?\n"); // Demande à l'utilisateur si il souhaite revenir aux options.
  scanf("%s" , restart); // Récupère sa réponse restart.

  // Convertit la chaîne de caractères en minuscules pour faciliter la comparaison.
  for (int i = 0; restart[i]; i++){ 
    restart[i] = tolower(restart[i]); 
  }

  // Si l'utilisateur veut revenir aux choix des options.
  if (strcmp(restart, "yes") == 0) {
    switchcase (); // Amène la fonction des choix des options dédié aux employee.
  }
    
  // Si l'utilisateur ne veut pas alors ..
  else if (strcmp(restart, "no") == 0) {
    printf("\n"); // Esapce pour améliorer l'interface.
    printf("\n"); // Esapce pour améliorer l'interface.
    EmployeeOrClient(); // Amène la fonction qui ramène le programme au début.
  }
  
  // Si l'utilisateur n'a pas utilisé le bon orthographe.
  else {
    printf("Try again while using the followings: 'yes' or 'no'.\n"); // Affiche donc l'utilisateur n'a pas écriyt le bon orthographe.
    RestartChoice(); // Amène la fonction qui demande si l'utilisateur veut revenir au choix des options.
  }
}




// Fonction qui demande pour relancer le programme au choix des options dans le switch case 2 dédié aux clients.
int RestartChoice2 () {
  
  char restart[MAX_SIZE];
  
  printf("\n"); // Esapce pour améliorer l'interface.
  printf("Would you like to do something else ?\n"); // Demande à l'utilisateur s'il veut revenir aux choix des options. 
  scanf("%s" , restart); // Récupère sa réponse.

  // Convertit la chaîne de caractères en minuscules pour faciliter la comparaison.
  for (int i = 0; restart[i]; i++){ 
    restart[i] = tolower(restart[i]); 
  }
    
  // Si l'utilisateur veut revenir aux choix des options.
  if (strcmp(restart, "yes") == 0) {
    switchcase2 (); // Amène la fonction des choix des options.
  }
  
  // Si l'utilisateur ne veut pas revenir aux choix des options.
  else if (strcmp(restart, "no") == 0) {
    printf("\n"); // Esapce pour améliorer l'interface.
    printf("\n"); // Esapce pour améliorer l'interface.
    EmployeeOrClient(); // Amène la fonction qui redémarre le programme au début.
  }
  
  // Si l'utilisateur n'a pas utiliser le bon orthopgraphe.
  else {
    printf("Try again while using the followings: 'yes' or 'no'.\n"); // Affiche à l'utilisateur qu'il n'a pas utiliser le bon orthographe.
    RestartChoice2(); // Amène la fonction qui demande si l'utilisateur veut revenir au choix des options.
  }
}




// Fonction qui affiche le choix des options pour les client.
int switchcase2 () {
  
  char choix;

  
  printf("\n\n"); // Esapce pour améliorer l'interface.
  printf("What do you want to do ?\n\n"); // Demande à l'utilisateur ce qu'il veut faire.
  printf("  1) See the products\n"); // Affiche l'option 1.
  printf("  2) Buy something.\n"); // Affiche l'option 2.
  printf("  4) Delete your profile.\n"); // Affiche l'option 3.
  printf("  5) Quit !\n\n"); // Affiche l'option 54.
  printf("Insert digit according to the action desired\n");
  
   // scanf("%d", &choix ); // Demande à l'utilisateur de saisir un choix.
  while (scanf("%d", &choix) != 1) {
    clearBuffer();
    printf("Invalid entry\n");
    printf("Please enter a valid number : \n");
  }
  

    // En fonction du choix de l'utilisateur, exécute plusieurs fonctions amenant au résultat voulu.
    switch(choix) {
      
      case 1: // Exécute le choix 1.
        printf("\n"); // Esapce pour améliorer l'interface.
        ChoiceShowAllProduit ();
        printf("\n"); // Esapce pour améliorer l'interface.
        RestartChoice2 (); // Amène la fonction qui demande si l'utilisateur veut revenir au choix des options.
        break; // Pour arrêter l'execution du choix 1.
      
      case 2: // Exécute le choix 2.
        printf("\n"); // Esapce pour améliorer l'interface.
        float prix;
        float Buy();
        prix = Buy();
        printf("\n"); // Esapce pour améliorer l'interface.
        RestartChoice2 (); // Amène la fonction qui demande si l'utilisateur veut revenir au choix des options.
        break; // Pour arrêter l'execution du choix 2.
      
      case 3: // Exécute le choix 4.
        printf("\n"); // Esapce pour améliorer l'interface.
        DeleteProfile ();
        variabletest =0; 
        printf("\n"); // Esapce pour améliorer l'interface.
        RestartChoice2 (); // Amène la fonction qui demande si l'utilisateur veut revenir au choix des options.
        break; // Pour arrêter l'execution du choix 4.
      
      case 4: // Exécute le choix 5, qui va relancer le programme au début.
        printf("\n"); // Esapce pour améliorer l'interface.
        printf("Goodbye!\n"); 
        printf("\n"); // Esapce pour améliorer l'interface.
        printf("\n"); // Esapce pour améliorer l'interface.
      variabletest=0;
        EmployeeOrClient (); // Amène la fonction qui redémarre le programme au début.
        break; // Pour arrêter l'execution du choix 5.
      
      default: // Exécute le choix autres, qui va relancer le programme d'affichage des choix.
        printf("\n"); // Esapce pour améliorer l'interface.
        printf("Invalid choice, please try again.\n"); // Affiche que le choix saisi n'est pas compris dans les choix affichés.
        // Esapce pour améliorer l'interface.
        switchcase2() ; // Amène qui la fonction qui relan,ce l'affiche des options.
        break; // Pour arrêter le switch case 2.
    }

}



// Fonction qui affiche le choix des options pour les employee.
int switchcase () {
  
  int choix;
  int mdp;
  
  printf("\n\n"); // Esapce pour améliorer l'interface.
  printf("What do you want to do ?\n\n"); // Demande à l'utilisateur ce qu'il veut faire.
  printf("  1) Display the list of clients.\n"); // Affiche l'option 1.
  printf("  2) Show products.\n"); // Affiche l'option 2.
  printf("  3) Show soon-to-be-null products.\n"); // Affiche l'option 3.
  printf("  4) Add a product.\n"); // Affiche l'option 4.
  printf("  5) Delete a product or client.\n"); // Affiche l'option 6.
  printf("  6) show unit in storage\n"); // Affiche l'option 7.
  printf("  7) Quit !\n\n"); // Affiche l'option 7.
  printf("Insert digit according to the action desired\n");
  
  //  While relié à la fonction clear buffer permettant de sécuriser les scanf.
  while (scanf("%d", &choix) != 1) {
    clearBuffer();
    printf("Invalid entry\n");
    printf("Please enter a valid number : \n");
  }
  
  // En fonction du choix de l'utilisateur, appelle une fonction
    switch(choix) {
      
      case 1: // Exécute le choix 1.
          printf("\n"); // Esapce pour améliorer l'interface.
          ChoiceReadAllClient(); // Amène la fonction qui va exécuter la demande du choix 1.
          RestartChoice (); // Amène la fonction qui demande si l'utilisateur veut revenir au choix des options.
          break; // Pour arrêter l'execution du choix 1.
      
      case 2: // Exécute le choix 2.
          ChoiceShowAllProduit(); // Amène la fonction qui va exécuter la demande du choix 1.
          RestartChoice (); // Amène la fonction qui demande si l'utilisateur veut revenir au choix des options.
          break; // Pour arrêter l'execution du choix 2.
      
      case 3: // Exécute le choix 3.
          printf("\n"); // Esapce pour améliorer l'interface.
          ShowLessProduit();
          printf("\n"); // Esapce pour améliorer l'interface.
          Show0Product();
          RestartChoice (); // Amène la fonction qui demande si l'utilisateur veut revenir au choix des options.
          break; // Pour arrêter l'execution du choix 3.
     
      case 4: // Exécute le choix 4.
          printf("\n"); // Esapce pour améliorer l'interface.
          AddProduit ();  // Amène la fonction qui va exécuter la demande du choix 1.
          RestartChoice (); // Amène la fonction qui demande si l'utilisateur veut revenir au choix des options.
          break; // Pour arrêter l'execution du choix 5.
      
      
      case 5: // Exécute le choix 5.
          printf("\n"); // Esapce pour améliorer l'interface.
          printf("Type in the password :\n");

          // While relié à la fonction permettant de sécuriser les scanf. 
          while (scanf("%d", &mdp) != 1) { // Récupère la réponse du mdp.
            clearBuffer();
            printf("Incorrect password\n");
            printf("Please insert password \n");
          }
          
          // Si le mot de passe est incorrect..
          if (mdp == 4321) {
            printf("\n"); // Esapce pour améliorer l'interface.
            printf("Your password is correct, access granted !\n"); // Affiche que le mot de passe est pas bon.
            printf("\n"); // Esapce pour améliorer l'interface.
            DeleteProduct (); // Amène la fonction pour supprimer un produit ou un client.
          }

          // Si le mot de passe est pas bon..
          else {
            printf("\n"); // Esapce pour améliorer l'interface.
            printf("Password incorrect !\n"); // Affiche que le mot de passe est bon.
            printf("\n"); // Esapce pour améliorer l'interface.
            switchcase (); // Amène la fonction pour supprimer un produit ou un client.
          }
          
          printf("\n"); // Esapce pour améliorer l'interface.
          RestartChoice (); // Amène la fonction qui demande si l'utilisateur veut revenir au choix des options.
          break; // Pour arrêter l'execution du choix 5.
      
      case 6:
        printf("\n");
        unitProduct ();
        RestartChoice ();
        break;
     
      case 7: // Exécute le choix 7, qui va relancer le programme au début.
          printf("\n"); // Esapce pour améliorer l'interface.
          printf("Goodbye!\n"); // Affiche au revoir.
          printf("\n"); // Esapce pour améliorer l'interface.
          printf("\n"); // Esapce pour améliorer l'interface.
          EmployeeOrClient(); // Amène la fonction qui redémarre le programme au début.
          break; // Pour arrêter l'execution du choix 7.
     
      default: // Exécute le choix autres, qui va exécuter la fonction qui redémarre le programme d'affichage des choix.
          printf("\n"); // Esapce pour améliorer l'interface.
          printf("Invalid choice, please try again.\n"); // Affiche que le choix choisi n'est pas compris dans les choix affichés.
          printf("\n"); // Esapce pour améliorer l'interface.
          printf("\n"); // Esapce pour améliorer l'interface.
          switchcase() ; // Amène la fonction qui relancer l'affichage des options.
          break; // Pour arrêter le switch case 1.
    }
}




// Fonction permettant la recherche du nom et prénom du client. Pourquoi * dans () -->  En résumé, l'utilisation ou non d'un astérisque () dans la déclaration d'une fonction dépend de la manière dont vous souhaitez passer et manipuler l'objet en question. Si vous souhaitez passer une copie de l'objet, vous n'avez pas besoin d'utiliser un pointeur. Si vous souhaitez modifier directement l'objet d'origine, vous pouvez utiliser un pointeur en ajoutant une étoile () dans la déclaration de la fonction.
int SearchName(Profile client_exist) {
    
    FILE *fichier_clients;
  char line[MAX_SIZE];
  int variableFound = 0;
  int numero_reference;
  variabletest=0;

  printf("- Familly name : "); // Demande le nom de famille.
  
  // Do, demander le nom ..
  do {
  scanf("%s", client_exist.nom);// L'utilisation de -> revient directement au fait qu'on utilise la strcut Profile clien_exist avec * dans les () de la fonction. Récupère la reponse client_exist.nom.

    for (int i = 0; client_exist.nom[i]; i++){ 
    client_exist.nom[i] = tolower(client_exist.nom[i]); 
  }
    
    // Si la valeur est inférieur à 3 alors
    if (strlen(client_exist.nom) < 3) {
     printf("Please insert at least 3 letters\n"); // Demande à l'utilisateur d'utiliser 3 lettres minimum.
      printf("- Family name : "); // Redemande le nom de famille.
    }

  // Tant que la valeur entrée est < à 3.
  } while (strlen(client_exist.nom) < 3);
  
  printf("- First name   : "); // Demande le prénom.
  
  // Do, demander le prénom ..
  do {
  scanf("%s", client_exist.prenom); // Récupère la reponse client_exist.nom.
    for (int i = 0; client_exist.prenom[i]; i++){ 
    client_exist.prenom[i] = tolower(client_exist.prenom[i]); 
  }
    // Si la valeur est inférieur à 3 alors
    if (strlen(client_exist.prenom) < 3) {
      printf("Please insert at least 3 letters\n"); // Demande à l'utilisateur d'utiliser 3 lettres minimum.
      printf("- First name : "); // Redemande le nom de famille.
    }

  // Tant que la valeur entrée est < à 3.
  } while (strlen(client_exist.prenom) < 3);

  fichier_clients = fopen("clients.txt", "r"); // Ouverture du fichier en utilisant le pointeur définit auparavant.
  
  // Si le fichier ne s'ouvre pas ..
  if (fichier_clients == NULL) {
    printf("Error occured while opening file try again later.\n"); // Message d'erreur.
    return 1; // return 1.
  }

  // Le while répéte l'opération pour toutes les lignes.
  while (fgets(line, sizeof(line), fichier_clients) != NULL) { 
  // fgets lit une ligne (line) du fichier (fichier_clients), la condition "fgets(line, sizeof(line), fichier_clients) != NULL" vérifie si la lecture de la ligne a réussi avec le sizeof(line), si la condition = null c'est que c'est la fin du fichier donc on s'arrête, mais tant que c'est différent de null on continue à lire la ligne avec fget pour chaque ligne avec while.
  // Notre condition if dans le while va donc itérer l'opération à chaque ligne, si la condtion est validé alors on s'arrête est on ajoute variableFound = 1, pour dire que la variable a été trouvé, et le break pour s'arrêter. La fonction strstr est utilisé pour rechercher la variable en question client_exist.prenom dans la ligne line, et si la variable est trouvé alors ca renvoie une variable différente de null et améne au break.

    // Si avec la fonction strstr à la ligne (line), la variable (client_exist.prenom ET nom) sont detectés alors..
    if (strstr(line, client_exist.prenom) != NULL && strstr(line, client_exist.nom) != NULL) {
      variableFound = 1; // Activé la variable disant que le nom et prenom a été trouvé.
      sscanf(line, "%*s %*s %d %*s %*s %*s", &numero_reference); // Récupere la variable numero_reference.
      break; // Arrête la boucle.
      // En résumé, cette partie du code lit chaque ligne du fichier avec fgets et recherche la présence de la variable spécifiée avec strstr. Si la variable est trouvée, nous mettons variableFound à 1 et sortons de la boucle. Cela nous permet de savoir si la variable existe dans le fichier ou non.  
    }
  }

  // Si la variable VariableFOund = 1..
  if (variableFound) {
    printf("\n"); // Espace pour améliorer l'interface.
    printf("Account %s %s found, your client number %d.\n", client_exist.nom, client_exist.prenom, numero_reference);

    variabletest = numero_reference;
    
    printf("\n"); // Espace pour améliorer l'interface.
    printf("Welcome back %s !\n", client_exist.nom);
    printf("\n"); // Espace pour améliorer l'interface.
    switchcase2 (); // Ramène la fonction qui affiche les options pour le client.
  } 
  
  // Sinon si VariableFound = 0..
  else {
    printf("Account %s %s not found.\n", client_exist.nom, client_exist.prenom);
    printf("\n"); // Espace pour améliorer l'interface.
    printf("\n"); // Espace pour améliorer l'interface.
    EmployeeOrClient ();
  }

  fclose(fichier_clients);
  return 0;
}




// Fonction pour rechercher un client avec sa reference.
int searchref(Profile client_exist) {
    
    FILE* fichier_clients;
  char line[MAX_SIZE];
  int variableFound = 0;
  int refsearch;
  variabletest=0;
    
  printf("Enter your 4 digit client ID\n");

  do {
       
    while (scanf("%d", &refsearch) != 1) { // Récupère la réponse prix1 relié au typedef struct produit pour un nouveau produit.
      clearBuffer();
      printf("Invalid entry\n\n");
      printf("Please enter a valid number : \n\n");
    }
      
    //
    if (refsearch < 1000) {
      printf("\n");
      printf("Please insert at least 4 digits\n");
      printf("\n"); // Espace pôur améliorer l'interface.
      }

    } while (refsearch < 1000);

    fichier_clients = fopen("clients.txt", "r");

    if (fichier_clients == NULL) {
      printf("Error occurred while opening the file. Please try again later.\n");
      return 1;
    }

    //
    while (fgets(line, sizeof(line), fichier_clients) != NULL) {
      sscanf(line, "%*s %*s %d", &(client_exist.ref));

      //
      if (client_exist.ref == refsearch) {
        variableFound = 1;
        sscanf(line, "%s %s %*s %*s %*s %*s", client_exist.prenom, client_exist.nom); 
        break;
      }
    }

    //
    if (variableFound) {
      printf("\n");
      printf("Account %s %s found, your client number %d.\n", client_exist.nom, client_exist.prenom, refsearch);

      variabletest = client_exist.ref;
      printf("\n");
      printf("Welcome back %s!\n", client_exist.nom);
      printf("\n");

      printf("%d", variabletest);
      
      switchcase2();
    } 

    //
    else {
      printf("Account %d not found.\n", refsearch);
      printf("\n"); // Espace pour améliorer l'interface.
      printf("\n"); // Espace pour améliorer l'interface.
      EmployeeOrClient();
    }

    fclose(fichier_clients);

  return variabletest;
}




// Fonction pour le choix 1 employee, lire la liste des clients.
int ChoiceReadAllClient () {
  
  int numprofile;
  
  printf("The list of clients is the following :\n"); // Affiche un message d'intro pour dire la liste des clients.
  printf("\n");
    // Ouvre le fichier des clients existants.
    FILE *fichier = fopen("clients.txt", "r"); // Ouvre le fichier.

  // Si le fichier ne s'ouvre pas ..
  if (fichier == NULL) {
    printf("\n"); // Espace pour améliorer l'interface
    printf("Error occured while opening file try again later.\n"); // Affiche un message d'erreur si le fichier ne s'ouvre pas.
    return 1; // return 1.
  }

  Profile client; // Amène le typedef struct client, pour clients.
  client.numprofile = numprofile;

  // Instructions ci-dessous.
  while (fscanf(fichier, "%s %s %d %*s %*s %*s", client.prenom, client.nom, &numprofile) != EOF) {
    
    
    if (( strcmp( client.nom, "NULL") != 0 ) && ( strcmp( client.prenom, "NULL")!=0))
    
    {
      
    printf("  Familly name: %s, First name: %s, Client number : %d\n\n", client.nom, client.prenom, numprofile); // Affiche les noms de famille et prénoms. 
  } // Boucle while qui lit les informations stockées dans le fichier "clients.txt" ligne par ligne. La fonction fscanf() lit une ligne à chaque itération de la boucle, et stocke les valeurs lues dans les variables nom et prenom, respectivement. L'expression "!= EOF" est utilisée pour vérifier si la fin du fichier a été atteinte. EOF (End of File) est une constante définie dans la bibliothèque standard C qui est renvoyée lorsque la fin d'un fichier est atteinte. La boucle while continue de s'exécuter jusqu'à ce que fscanf() atteigne la fin du fichier et renvoie EOF, ce qui met fin à la boucle.
  }
  
    fclose(fichier); // Fermeture du fichier.
  
  return 0; // return 0;

}




// Fonction d'affichage de tableau pour la fonction du choix 2 employee.
int afficherTableauProduit(Produit produit) {
  char tableau[3][3][40] = {
    {"Price     :  ", "Price     :  ", "Price     :  "},
    {"Quantity  :  ", "Quantity  :  ", "Quantity  :  "},
    {"", "", ""},
  };

  printf("\n"); // Espace pour améliorer l'interface.
  printf("\n"); // Espace pour améliorer l'interface.
  printf("\n"); // Espace pour améliorer l'interface.
  
  printf("Name of this Fragrance for '%s' is: %s\n", produit.typ, produit.nom);
  printf("Reference number is: %d\n", produit.reference);
  printf("\n"); // Espace pour améliorer l'interface.
  printf("\n"); // Espace pour améliorer l'interface.
  printf("  |        50ml           |        100ml          |        200ml          |\n");
  printf("---------------------------------------------------------------------------\n");
  for (int i = 0; i < 1; i++) {
    printf("%d | %-11s%6.2lf € | %-11s%6.2lf € | %-11s%6.2lf € |\n", i+1, tableau[i][0], produit.price1, tableau[i][1], produit.price2, tableau[i][2], produit.price3);
    for (int j = 1; j < 2; j++) {
      printf("%d | %-11s%2d       | %-11s%2d       | %-11s%2d       |\n", j+1, tableau[j][0], produit.quantity1, tableau[j][1], produit.quantity2, tableau[j][2], produit.quantity3);
      for (int k = 2; k < 3; k++) {
        printf("  |                       |                       |                       |\n"); 
      }
    }
  }
}




// Fonction pour le choix 2 employee, lire la liste des produits.
int ChoiceShowAllProduit () {

  char type[MAX_SIZE];
  
  printf("\n"); // Espace pour améliorer l'interface.
  printf("Would you like to see what types of fragrances ?\n\n"); // Demande à l'utilisateur quel type de parfums veut-il afficher.
  printf("- Men's Fragrance\n");
  printf("- Women's Fragrance\n");
  printf("- Unisexe Fragrance\n");
  printf("- All\n");
  printf("\n");
  scanf("%s" , type); // Récupère sa réponse type.

  // Convertit la chaîne de caractères en minuscules pour faciliter la comparaison.
  for (int i = 0; type[i]; i++){
    type[i] = tolower(type[i]);
  }

  // Si le cas choisi est MEN.
  if (strcmp(type, "men") == 0 || strcmp(type, "mens") == 0 || strcmp(type, "men fragrance") == 0 || strcmp(type, "mens fragrance") == 0 || strcmp(type, "men's fragrance") == 0) {

      // Ouvre le fichier des produits hommes.
      FILE *fichier = fopen("produit.txt", "r");
    
    // Si le fichier s'ouvre pas ..
    if (fichier == NULL) {
      printf("\n"); // Espace pour améliorer l'interface.
      printf("Error occured while opening file try again later.\n"); // Affiche un message d'erreur si le fichier ne s'ouvre pas.
      return 1; // return 1.
    }

  Produit produit; // Amène le typedef struct Produit pour produits.

    // Instructions ci-dessous.
    while (fscanf(fichier, "%s %d %f %d %f %d %f %d %s\n", produit.nom, &produit.reference, &produit.price1, &produit.quantity1, &produit.price2, &produit.quantity2, &produit.price3, 
 &produit.quantity3, produit.typ ) != EOF) { //  l'opérateur '&' est utilisé pour obtenir l'adresse d'une variable, nécessaire pour écrire des valeurs à cette adresse en mémoire. Pour les tableaux, le nom du tableau représente déjà l'adresse de sa première cellule de mémoire, il n'est donc pas nécessaire d'utiliser l'opérateur '&' lors de la lecture ou de l'écriture de données dans un tableau.
      

      // Affiche uniquement le genre "men".
      if (strcmp(produit.typ, "men") == 0) {
        afficherTableauProduit(produit);
      }
    }
  }


  // Si le cas choisi est WOMEN.
  else if (strcmp(type, "women") == 0 || strcmp(type, "womens") == 0 || strcmp(type, "womens fragrance") == 0 || strcmp(type, "women fragrance") == 0 || strcmp(type, "women's fragrance") == 0) {
    
      // Ouvre le fichier des produits femmes.
      FILE *fichier = fopen("produit.txt", "r");
    
    // Si le fichier s'ouvre pas ..
    if (fichier == NULL) {
      printf("\n"); // Espace pour améliorer l'interface.
      printf("Error occured while opening file try again later.\n"); // Affiche un message d'erreur si le fichier ne s'ouvre pas.*
      return 1; // return 1.
    }
  
  Produit produit; // Amène le typedef struct Produit pour produits.
  
    // Instructions ci-dessous.
    while (fscanf(fichier, "%s %d %f %d %f %d %f %d %s\n", produit.nom, &produit.reference, &produit.price1, &produit.quantity1, &produit.price2, &produit.quantity2, &produit.price3, 
 &produit.quantity3, produit.typ )
     
     != EOF) { //  l'opérateur '&' est utilisé pour obtenir l'adresse d'une variable, nécessaire pour écrire des valeurs à cette adresse en mémoire. Pour les tableaux, le nom du tableau représente déjà l'adresse de sa première cellule de mémoire, il n'est donc pas nécessaire d'utiliser l'opérateur '&' lors de la lecture ou de l'écriture de données dans un tableau.

      // Affiche uniquement le genre women.
      if (strcmp(produit.typ, "women") == 0) {
        afficherTableauProduit(produit);
      }
    }
  }
  
  // Si le cas choisi est UNISEXE.
  else if (strcmp(type, "unisexe") == 0|| strcmp(type, "uni") == 0  || strcmp(type, "unisex") == 0 || strcmp(type, "unisexe fragrance") == 0 || strcmp(type, "unisex fragrance") == 0) {
      
      // Ouvre le fichier des produits unisexe.
      FILE *fichier = fopen("produit.txt", "r");
    
    // Si le fichier s'ouvre pas ..
    if (fichier == NULL) {
      printf("\n"); // Espace pour améliorer l'interface.
      printf("Error occured while opening file try again later.\n"); // Affiche un message d'erreur si le fichier ne s'ouvre pas.
      return 1; // return 1.
    }
  
  Produit produit; // Amène le typedef struct Produit pour produits.
  
    // Instructions ci-dessous.
    while (fscanf(fichier, "%s %d %f %d %f %d %f %d %s\n", produit.nom, &produit.reference, &produit.price1, &produit.quantity1, &produit.price2, &produit.quantity2, &produit.price3, 
 &produit.quantity3, produit.typ ) != EOF) { //  l'opérateur '&' est utilisé pour obtenir l'adresse d'une variable, nécessaire pour écrire des valeurs à cette adresse en mémoire. Pour les tableaux, le nom du tableau représente déjà l'adresse de sa première cellule de mémoire, il n'est donc pas nécessaire d'utiliser l'opérateur '&' lors de la lecture ou de l'écriture de données dans un tableau.

      // Affiche uniquement le genre unisexe.
      if (strcmp(produit.typ, "unisexe") == 0) {
        afficherTableauProduit(produit);
      }
    }
  }

  // Si le cas choisi est all..
  else if (strcmp(type, "all") == 0) {
      
      // Ouvre le fichier des produits unisexe.
      FILE *fichier = fopen("produit.txt", "r");
    
    // Si le fichier s'ouvre pas ..
    if (fichier == NULL) {
      printf("\n"); // Espace pour améliorer l'interface.
      printf("Error occured while opening file try again later.\n"); // Affiche un message d'erreur si le fichier ne s'ouvre pas.
      return 1; // return 1.
    }
  
  Produit produit; // Amène le typedef struct Produit pour produits.
  
    // Instructions ci-dessous.
    while (fscanf(fichier, "%s %d %f %d %f %d %f %d %s\n", produit.nom, &produit.reference, &produit.price1, &produit.quantity1, &produit.price2, &produit.quantity2, &produit.price3, 
 &produit.quantity3, produit.typ ) != EOF) { //  l'opérateur '&' est utilisé pour obtenir l'adresse d'une variable, nécessaire pour écrire des valeurs à cette adresse en mémoire. Pour les tableaux, le nom du tableau représente déjà l'adresse de sa première cellule de mémoire, il n'est donc pas nécessaire d'utiliser l'opérateur '&' lors de la lecture ou de l'écriture de données dans un tableau.

      // Affiche uniquement le genre unisexe.
      if (strcmp(produit.typ, "unisexe") == 0 || strcmp(produit.typ, "men") == 0 || strcmp(produit.typ, "women") == 0) {
        afficherTableauProduit(produit);
      }
    }
  }

  // Si l'utilisateur a fait une erreur de saisie.
  else {
    printf("Try again while using the followings: 'Mens', 'Womens', 'Unisexe' or 'All'.\n"); // Demande à l'utilisateur de réessayer avec le bon orthographe.
    ChoiceShowAllProduit () ; // Amène la fonction qui redémarre le programme de choix 2, d'affichage des produits.
  }
}



  
int compareProduits(const void* a, const void* b) {
    
  const Produit* produitA = (const Produit*)a;
  const Produit* produitB = (const Produit*)b;

  // Tri par quantité décroissante de la colonne 1
  int diffQuantity1 = produitB->quantity1 - produitA->quantity1;
  if (diffQuantity1 != 0) {
    return diffQuantity1;
  }

  // Si quantité1 égale, tri par quantité décroissante de la colonne 2
  int diffQuantity2 = produitB->quantity2 - produitA->quantity2;
  if (diffQuantity2 != 0) {
    return diffQuantity2;
  }

  // Si quantité2 égale, tri par quantité décroissante de la colonne 3
  int diffQuantity3 = produitB->quantity3 - produitA->quantity3;
  if (diffQuantity3 != 0) {
    return diffQuantity3;
  }

  // Si quantité3 égale, tri par nom croissant
  return strcmp(produitA->nom, produitB->nom);
}





int ShowLessProduit() {
    Produit* produits = NULL;
    int numProduits = 0;

    FILE* file = fopen("produit.txt", "r");
    if (file == NULL) {
        printf("Error occurred while opening the file. Please try again later.\n");
        return -1;
    }

    char nom[100];
    int reference;
    float price1, price2, price3;
    int quantity1, quantity2, quantity3;
    char typ[20];

    while (fscanf(file, "%s %d %f %d %f %d %f %d %s", nom, &reference, &price1, &quantity1, &price2, &quantity2, &price3, &quantity3, typ) == 9) {
        Produit* nouveauProduit = (Produit*)malloc(sizeof(Produit));
        if (nouveauProduit == NULL) {
            printf("Error with memory allocation.\n");
            break;
        }

        strncpy(nouveauProduit->nom, nom, sizeof(nouveauProduit->nom));
        nouveauProduit->reference = reference;
        nouveauProduit->price1 = price1;
        nouveauProduit->quantity1 = quantity1;
        nouveauProduit->price2 = price2;
        nouveauProduit->quantity2 = quantity2;
        nouveauProduit->price3 = price3;
        nouveauProduit->quantity3 = quantity3;
        strncpy(nouveauProduit->typ, typ, sizeof(nouveauProduit->typ));

        produits = (Produit*)realloc(produits, (numProduits + 1) * sizeof(Produit));
        produits[numProduits] = *nouveauProduit;
        numProduits++;

        free(nouveauProduit);

        if (numProduits == MAX_PRODUITS) {
            printf("Maximum number of products has been reached.\n");
            break;
        }
    }

    fclose(file);

    qsort(produits, numProduits, sizeof(Produit), compareProduits);

    printf("The lowest 5 products in stock are the following:\n\n");
    printf("|           Products             |         50mL         |         100mL        |         200mL        |\n");
    printf("-------------------------------------------------------------------------------------------------------\n");
    printf("|                                |                      |                      |                      |\n");
    for (int i = 0; i < 5; i++) {
    printf("| %-31s|          %-02d          |          %-02d          |          %-02d          |\n", produits[i].nom, produits[i].quantity1, produits[i].quantity2, produits[i].quantity3);
    }

    free(produits);

    return 0;
}






int Show0Product () {
   
    FILE *fp = fopen ("produit.txt", "r"); // Ouverture du fichier avec le pointeur.
  char nul[MAX_SIZE];

  Produit produit; // Amène le typedef struct produit.

  // Si le fichier ne s'ouvre pas ..
  if ( fp == NULL) {
    printf("Error occured while opening file try again later.\n"); // Affiche un message d'erreur.
    return -1; // return -1.
  }

  printf("Do you want to see Products out of stock ?\n\n"); // Demande si l'utilisateur veut voir les produits nuls.
  scanf("%s", nul); // Récupère la réponse nul.

  for (int i = 0; nul[i]; i++){
        nul[i] = tolower(nul[i]);
      }

  // Si l'utilisateur veut voir les produits nuls..
  if (strcmp(nul, "yes") == 0) {

    int a;
    a = 0;
    int b;
    b = 0;
    int c;
    c = 0;
    int numProduits;
    numProduits = 0;
    
    // While avec fgets lit une ligne par une ligne jusqu'au EOF du fichier, fscanf lit les variables precisées.
    while (fscanf(fp, "%s %d %f %d %f %d %f %d %s\n", produit.nom, &produit.ref, &produit.price1, &produit.quantity1, &produit.price2, &produit.quantity2, &produit.price3, &produit.quantity3, produit.typ) != EOF) {

      numProduits++;

      // Si quantity1 faible..
      if ( produit.quantity1 == 0 )  {
        printf("\n"); // Espace pour améliorer l'interface.
        printf("Product out of stock | %s, for the 50 mL\n", produit.nom); // Affiche un message d'alerte.
        a++;
      }
    
      // Si quantity2 faible ..
      if ( produit.quantity2 == 0) {
        printf("\n"); // Espace pour améliorer l'interface.
        printf("Product out of stock | %s, for the 100 mL\n", produit.nom); // Affiche un message d'alerte.
        b++;
      }


      // Si quantity3 faible..
      if ( produit.quantity3 == 0 ) {
        printf("\n"); // Espace pour améliorer l'interface.
        printf("Product out of stock | %s, for the 200 mL\n", produit.nom); // Affiche un message d'alerte.
        c++;
      }
    }
    
    fclose(fp); // Fermeture du fichier.

    // Si les 50ml sont tous à 0 ..
    if ( a == numProduits) {
      printf("\n"); // Espace pour améliorer l'interface.
      printf("All products in stock in 50mL in stock are sold out.\n"); // Indique que les 50ml sont hs.
    }

    // Si les 100ml sont tous à 0 ..
    if ( b == numProduits ) {
      printf("\n"); // Espace pour améliorer l'interface.
      printf("All products in stock in 100mL in stock are sold out.\n"); // Indique que les 100ml sont hs.
    }

    // Si les 200ml sont tous à 0 ..
    if ( c == numProduits ) {
      printf("\n"); // Espace pour améliorer l'interface.
      printf("All products in stock in 200mL in stock are sold out.\n"); // Indique que les 200ml sont hs.
    }
  }
  
  
  // Si l'utilisateur ne veut pas.
  else if (strcmp(nul, "no") == 0) {
    printf("\n"); // Espace pour améliorer l'interface.
    
    // Espace pour améliorer l'interface.
    RestartChoice ();
  }

  // Si l'utilisateur fait une erreur de saisie..
  else {
    printf("\n"); // Espace pour améliorer l'interface.
    printf("Try again while using the followings: 'yes' or 'no'.\n");
    Show0Product ();
  }
}




                   // Fonction pour le choix 4 employee, pour ajouter un produit.
int AddProduit (somme) {
  
  char type[MAX_SIZE];
  char line[MAX_SIZE];
  
  printf("Do you want to add Men's fragrance, Women's fragrance, or Unisex fragrance ?\n\n"); // Demande quel type de parfums veuit-il ajouter.
  scanf("%s" , type); // Récupère la réponse type.

  // Convertit la chaîne de caractères en minuscules pour faciliter la comparaison.
  for (int i = 0; type[i]; i++){ 
    type[i] = tolower(type[i]); 
  }

  // Si le parfums choisi est un parfums d'homme ..
  if (strcmp(type, "men's fragrance") == 0 || strcmp(type, "mens fragrance") == 0 || strcmp(type, "mens") == 0 || strcmp(type, "men") == 0) {
    
    Produit nouveau_produit; // Amène le typedef struct produit, pour un nouveau produit.
    
    printf("Name :"); // Affiche nom.
    scanf("%s", nouveau_produit.nom); // Récupère la réponse nom relié au typedef struct produit pour un nouveau produit.
    printf("\n");
    printf("Price of 50mL :"); // Affiche Prix.
    
      // While relié à la fonction permettant de sécuriser les scanf. 
      while (scanf("%f", &nouveau_produit.price1) != 1) { // Récupère la réponse prix1 relié au typedef struct produit pour un nouveau produit.
      clearBuffer();
      printf("Invalid entry\n");
    printf("Please enter a valid number : \n");
      }
    printf("Quantity of 50mL:"); // Affiche Quantité.
      
    // While relié à la fonction permettant de sécuriser les scanf. 
    while (scanf("%d", &nouveau_produit.quantity1) != 1) { // Récupère la réponse quantite1 relié au typedef struct produit pour un nouveau produit.
      clearBuffer();
      printf("Invalid entry\n");
    printf("Please enter a valid number : \n");
    }
    printf("\n");
    printf("Price of 100mL :"); 
    
    // While relié à la fonction permettant de sécuriser les scanf. 
    while (scanf("%f", &nouveau_produit.price2) != 1) { // Récupère la réponse prix2 relié au typedef struct produit pour un nouveau produit.
      clearBuffer();
      printf("Invalid entry\n");
    printf("Please enter a valid number : \n");
    }
    printf("Quantity of 100 mL:"); // Affiche Quantité.
    
    // While relié à la fonction permettant de sécuriser les scanf. 
    while (scanf("%d", &nouveau_produit.quantity2) != 1) { // Récupère la réponse quantity2 relié au typedef struct produit pour un nouveau produit.
      clearBuffer();
      printf("Invalid entry\n");
    printf("Please enter a valid number : \n");
    }
    printf("\n");
    printf("Price of 200 mL:"); // Affiche Prix.
    // While relié à la fonction permettant de sécuriser les scanf. 
    while (scanf("%f", &nouveau_produit.price3) != 1) { // Récupère la réponse prix3 relié au typedef struct produit pour un nouveau produit.
      clearBuffer();
      printf("Invalid entry\n");
    printf("Please enter a valid number : \n");
    } 
    printf("Quantity 200 mL:"); // Affiche Quantité.
    // While relié à la fonction permettant de sécuriser les scanf. 
    while (scanf("%d", &nouveau_produit.quantity3) != 1) { // Récupère la réponse quantity3 relié au typedef struct produit pour un nouveau produit.
      clearBuffer();
      printf("Invalid entry\n");
    printf("Please enter a valid number : \n");
    }
    printf("\n");
    printf("Refrence number :"); // Affiche numéro de référence.
    
    // While relié à la fonction permettant de sécuriser les scanf. 
    while (scanf("%d", &nouveau_produit.reference) != 1) { // Récupère la réponse ref relié au typedef struct produit pour un nouveau produit.
      clearBuffer();
      printf("Invalid entry\n");
      printf("Please enter a valid number : \n");
    }
    strcpy(nouveau_produit.typ, "men"); // Stocke le char typ "men" dans la variable nouveau_produit.typ grâce à la fonction strcpy.

    Produit produit; // Amène le typedef strcut produit.

    // Ouverture du fichier en mode écriture.
    FILE *fichier_produit = fopen("produit.txt", "r");
    FILE *tempo = fopen("tempo.txt", "w");

    //Si un des deux fichier ne s'ouvre pas .. 
    if (fichier_produit == NULL || tempo == NULL) { 
      printf("Error occured while opening file try again later.\n"); // Message d'erreur. 
      exit(1); // Fin du programme 
    }

    //
    if (fichier_produit != NULL || strcmp(produit.nom, nouveau_produit.nom) == 0 || nouveau_produit.reference == produit.reference) { // Vérifie si le fichier a été ouvert avec succès.
      
      // Lit ligne par ligne.
      while (fscanf(fichier_produit, "%s %d %f %d %f %d %f %d %s", produit.nom, &produit.reference, &produit.price1, &produit.quantity1, &produit.price2, &produit.quantity2, &produit.price3, &produit.quantity3, produit.typ) == 9) {
            
        // Si il trouve un nom existant.
        if (strcmp(produit.nom, nouveau_produit.nom) == 0) {
        
          fprintf(tempo, "%s %d %f %d %f %d %f %d %s", produit.nom, produit.reference, produit.price1, produit.quantity1, produit.price2, produit.quantity2, produit.price3, produit.quantity3, produit.typ);
        }

        //
        else {
          fprintf(tempo, "%s %d %f %d %f %d %f %d %s", produit.nom, produit.reference, produit.price1, produit.quantity1, produit.price2, produit.quantity2, produit.price3, produit.quantity3, produit.typ);
          
        }
          
        // Si il trouve une reference existante..
        if (nouveau_produit.reference == produit.reference) {
          printf("Reference number is already in use for another product !\n");
        }
    }
        fclose(tempo);
        fclose(fichier_produit);
        remove("produit.txt");
        rename("tempo.txt", "produit.txt");
}
   
    
      // Ouverture du fichier en mode écriture.
      FILE *fichier_produit2 = fopen("produit.txt", "a");

      // Si le fichier s'ouvre ..
      if (fichier_produit2 != NULL) {
        fprintf(fichier_produit2, "%s %d %.2f %d %.2f %d %.2f %d %s\n", nouveau_produit.nom,nouveau_produit.reference, nouveau_produit.price1, nouveau_produit.quantity1,nouveau_produit.price2, nouveau_produit.quantity2,nouveau_produit.price3, nouveau_produit.quantity3, nouveau_produit.typ); // Écriture du nom, prix, quantité, référence dans le fichier.
        fclose(fichier_produit2); // Fermeture du fichier.
      }
      
      // Si le fichier ne s'ouvre pas ..
      else {
        printf("Error opening file produit.txt\n"); // Message d'erreur si le fichier ne s'ouvre pas.
      }
    
  }

  // Si le parfums choisi est un parfums de femme.
  else if (strcmp(type, "women's fragrance") == 0 || strcmp(type, "womens fragrance") == 0 || strcmp(type, "women") == 0 || strcmp(type, "womens") == 0) {
    
    Produit produit; // Amène le typedef struct produit just epour la somme.
    int totalProduits = unitProduct(produit); // Appel de la fonction unitProduct avec l'instance de la structure Produit
    if ( totalProduits < 700 ) {
      Produit nouveau_produit; // Amène le typedef struct produit, pour un nouveau produit.
      printf("Name :"); // Affiche nom.
      scanf("%s", nouveau_produit.nom); // Récupère la réponse nom relié au typedef struct produit pour un nouveau produit.
      printf("\n");
      printf("Price of 50mL :"); // Affiche Prix.
    
      // While relié à la fonction permettant de sécuriser les scanf. 
      while (scanf("%f", &nouveau_produit.price1) != 1) {  // Récupère la réponse prix relié au typedef struct produit pour un nouveau produit.
        clearBuffer();
        printf("Invalid entry\n");
        printf("Please enter a valid number : \n");
      }
      printf("Quantity of 50mL:"); // Affiche Quantité.
    
      // While relié à la fonction permettant de sécuriser les scanf. 
      while (scanf("%d", &nouveau_produit.quantity1) != 1) {  // Récupère la réponse quantity1 relié au typedef struct produit pour un nouveau produit.
        clearBuffer();
       printf("Invalid entry\n");
       printf("Please enter a valid number : \n");
      }
      printf("\n");
      printf("Price of 100mL :"); 
    
      // While relié à la fonction permettant de sécuriser les scanf. 
      while (scanf("%f", &nouveau_produit.price2) != 1) {  // Récupère la réponse prix2 relié au typedef struct produit pour un nouveau produit.
        clearBuffer();
        printf("Invalid entry\n");
        printf("Please enter a valid number : \n");
      } 
      printf("Quantity of 100 mL:"); // Affiche Quantité.
    
      // While relié à la fonction permettant de sécuriser les scanf. 
      while (scanf("%d", &nouveau_produit.quantity2) != 1) {  // Récupère la réponse quantity2 relié au typedef struct produit pour un nouveau produit.
        clearBuffer();
        printf("Invalid entry\n");
        printf("Please enter a valid number : \n");
      }
      printf("\n");
      printf("Price of 200 mL:"); // Affiche Prix.
    
      // While relié à la fonction permettant de sécuriser les scanf. 
      while (scanf("%f", &nouveau_produit.price3) != 1) {  // Récupère la réponse prix3 relié au typedef struct produit pour un nouveau produit.
        clearBuffer();
        printf("Invalid entry\n");
        printf("Please enter a valid number : \n");
      } 
      printf("Quantity 200 mL:"); // Affiche Quantité.
    
      // While relié à la fonction permettant de sécuriser les scanf. 
      while (scanf("%d", &nouveau_produit.quantity3) != 1) {  // Récupère la réponse quantity3 relié au typedef struct produit pour un nouveau produit.
        clearBuffer();
        printf("Invalid entry\n");
        printf("Please enter a valid number : \n");
      }
      printf("\n");
      printf("Refrence number :"); // Affiche numéro de référence.
   
      // While relié à la fonction permettant de sécuriser les scanf. 
      while (scanf("%d", &nouveau_produit.reference) != 1) {  // Récupère la réponse ref relié au typedef struct produit pour un nouveau produit.
        clearBuffer();
        printf("Invalid entry\n");
        printf("Please enter a valid number : \n");
      } // Récupère la réponse ref relié au typedef struct produit pour un nouveau produit.
      strcpy(nouveau_produit.typ, "women"); // Stocke le char typ "men" dans la variable nouveau_produit.typ grâce à la fonction strcpy.

      // Ouverture du fichier en mode écriture.
      FILE *fichier_produit = fopen("produit.txt", "a");
      
        // Si le produit s'ouvre ..
        if (fichier_produit != NULL) {
          fprintf(fichier_produit, "%s %d %.2f %d %.2f %d %.2f %d %s\n", nouveau_produit.nom,nouveau_produit.reference, nouveau_produit.price1, nouveau_produit.quantity1,nouveau_produit.price2, nouveau_produit.quantity2,nouveau_produit.price3, nouveau_produit.quantity3, nouveau_produit.typ); // Écriture du nom, prix, quantité, référence dans le fichier.
          fclose(fichier_produit); // Fermeture du fichier.
      }
      
        // Si le fichier ne s'ouvre pas ..
        else {
          printf("Error opening file produit.txt\n"); // Message d'erreur si le fichier ne s'ouvre pas.
        }
    }
  }
  
  // Si le parfums choisi est un parfums unisexe.
  else if (strcmp(type, "unisexe") == 0 || strcmp(type, "unisex") ==0 || strcmp(type, "uni") == 0) {

     Produit produit; // Amène le typedef struct produit just epour la somme.
    int totalProduits = unitProduct(produit); // Appel de la fonction unitProduct avec l'instance de la structure Produit
    if ( totalProduits < 700 ) {
    
    Produit nouveau_produit; // Amène le typedef struct produit, pour un nouveau produit.
    printf("Name :"); // Affiche nom.
    scanf("%s", nouveau_produit.nom); // Récupère la réponse nom relié au typedef struct produit pour un nouveau produit.
    printf("\n");
    printf("Price of 50mL :"); // Affiche Prix.
   
    // While relié à la fonction permettant de sécuriser les scanf. 
    while (scanf("%f", &nouveau_produit.price1) != 1) {  // Récupère la réponse prix1 relié au typedef struct produit pour un nouveau produit.
      clearBuffer();
      printf("Invalid entry\n");
      printf("Please enter a valid number : \n");
    } 
    printf("Quantity of 50mL:"); // Affiche Quantité.
    printf("\n");
    
    // While relié à la fonction permettant de sécuriser les scanf. 
    while (scanf("%d", &nouveau_produit.quantity1) != 1) {  // Récupère la réponse quantity1 relié au typedef struct produit pour un nouveau produit.
      clearBuffer();
      printf("Invalid entry\n");
    printf("Please enter a valid number : \n");
    }
    printf("Price of 100mL :"); 
    
    // While relié à la fonction permettant de sécuriser les scanf. 
    while (scanf("%f", &nouveau_produit.price2) != 1) {  // Récupère la réponse prix2 relié au typedef struct produit pour un nouveau produit.
      clearBuffer();
      printf("Invalid entry\n");
      printf("Please enter a valid number : \n"); 
    }
    printf("Quantity of 100 mL:"); // Affiche Quantité.
    
    // While relié à la fonction permettant de sécuriser les scanf. 
    while (scanf("%d", &nouveau_produit.quantity2) != 1) {  // Récupère la réponse quantite2 relié au typedef struct produit pour un nouveau produit.
      clearBuffer();
      printf("Invalid entry\n");
      printf("Please enter a valid number : \n");
    }
    printf("\n");
    printf("Price of 200 mL:"); // Affiche Prix.

    // While relié à la fonction permettant de sécuriser les scanf. 
    while (scanf("%f", &nouveau_produit.price3) != 1) {  // Récupère la réponse prix3 relié au typedef struct produit pour un nouveau produit.
      clearBuffer();
      printf("Invalid entry\n");
      printf("Please enter a valid number : \n");
    }
    printf("Quantity 200 mL:"); // Affiche Quantité.
 
    // While relié à la fonction permettant de sécuriser les scanf. 
    while (scanf("%d", &nouveau_produit.quantity3) != 1) {  // Récupère la réponse quantite3 relié au typedef struct produit pour un nouveau produit.
      clearBuffer();
      printf("Invalid entry\n");
      printf("Please enter a valid number : \n");
    }
    printf("\n");
    printf("Refrence number :"); // Affiche numéro de référence.
    
    // While relié à la fonction permettant de sécuriser les scanf. 
    while (scanf("%d", &nouveau_produit.reference) != 1) {  // Récupère la réponse ref relié au typedef struct produit pour un nouveau produit.
      clearBuffer();
      printf("Invalid entry\n");
      printf("Please enter a valid number : \n");
    }
    strcpy(nouveau_produit.typ, "unisexe"); // Stocke le char typ "men" dans la variable nouveau_produit.typ grâce à la fonction strcpy.
 
    // Ouverture du fichier en mode écriture.
    FILE *fichier_produit = fopen("produit.txt", "a");
      
      // Si le produit s'ouvre ..
      if (fichier_produit != NULL) {
        fprintf(fichier_produit, "%s %d %.2f %d %.2f %d %.2f %d %s\n", nouveau_produit.nom,nouveau_produit.reference, nouveau_produit.price1, nouveau_produit.quantity1,nouveau_produit.price2, nouveau_produit.quantity2,nouveau_produit.price3, nouveau_produit.quantity3, nouveau_produit.typ); // Écriture du nom, prix, quantité, référence dans le fichier.
        fclose(fichier_produit); // Fermeture du fichier.
      }
      
      // Si le fichier ne s'ouvre pas ..
      else {
        printf("Error opening file produit.txt\n"); // Message d'erreur si le fichier ne s'ouvre pas.
      }
  }
  
  // Si l'utilisateur a fait une erreur de saisie.
  else {
    printf("\n"); // Esapce pour améliorer l'interface.
    printf("Try again while using the followings: 'Men's Fragrance' or 'Women's Fragrance' or 'Unisexe'.\n"); // Demande à l'utilisateur de réessayer avec le bon orthographe.
    printf("\n"); // Esapce pour améliorer l'interface.
    AddProduit() ; // Amène la fonction pour redémarrer le programme à au choix 4.
  }
  }
  return 0; 
}




// Fonction pour le choix 6 employee, pour supprimer un produit.
int DeleteProduct () {
  
  int delete;
  int numeroLigne = 1;
  char line[1000];
  char type[MAX_SIZE];
  int ref;
  char str_ref[10];
  int lineNumber = 1;

  Profile client_exist;
  
  
  printf("Would you like to delete a product or a client ?\n"); // Demande qu'est ce qu'il veut supprimer.
  scanf("%s" , type); // Récupère la réponse type.


  for (int i = 0; type[i]; i++){ 
    type[i] = tolower(type[i]); 
  }
  
  // Si le cas choisi est un client.
  if (strcmp(type, "client") == 0 ) {
    printf("\n"); // Espace pour améliorer l'interface.
    printf("Insert the number of the client you want t ?\n"); // Demande quelle ref l'utilisateur souhaite supprimer.
   
    // While relié à la fonction permettant de sécuriser les scanf. 
    while (scanf("%d", &ref) != 1) { // Récupère la réponse delete, quelle ligne supprimer.
      clearBuffer();
      printf("Invalid entry\n");
    printf("Please enter a valid number : \n");
    }

      // Ouverture du fichier 1 principale en lecture et écriture.
      FILE *clients = fopen("clients.txt", "r+");

      // Ouverture du fichier temporaire en écriture.
      FILE *temp = fopen("temp.txt", "w");
   
    // Si un des deux fichier ne s'ouvre pas ..
    if (clients == NULL || temp == NULL) {
      printf("Error occured while opening file try again later.\n"); // Message d'erreur.
      exit(1); // Fin du programme
    }

    // Lit une ligne par une une ligne.
    while (fgets(line, sizeof(line), clients) != NULL) {

      sprintf(str_ref, "%d", ref);

      // Si il trouve la ref 
      if (strstr(line, str_ref) != NULL) {
        fprintf(temp, "%s %s %s %s %s %s \n", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL" ); // On écrit dans le nouveau fichier le nom et prenom par NULL.
      }

      // Sinon correspond aux autres lignes, en gros on les re écrits dans le nouveau fichier
      else {
        fputs(line, temp); // Fputs va remettre les lignes sans les modifier une par une grace à la boucle while.
      }
    
      lineNumber++; // LineNumber augmente de 1 à chaque fois pour faire l'opération avec toutes les lignes.
    }  
 
    fclose(clients); // Ferme le fichier 1.
    fclose(temp); // Ferme le fichier 2 temporaire.
    remove("clients.txt"); // Supprime l'ancien avec ligne indésirable.
    rename("temp.txt", "clients.txt"); // Renomme le nouveau fichier recopié sans la ligne indérisable comme l'ancien
    printf("\n"); // Espace pour améliorer l'interface.
    printf("Client deleted succesfully.\n"); // Confirme que l'opération a fini avec succès.
  }
   
  // Si le cas choisi est un produit.
  else if (strcmp(type, "product") == 0) {
    printf("\n"); // Espace pour améliorer l'interface.
    printf("Which line ?\n"); // Demande quelle ligne l'utilisateur souhaite supprimer.
        
    // While relié à la fonction permettant de sécuriser les scanf. 
    while (scanf("%d", &delete) != 1) { // Récupère la réponse delete, quelle ligne supprimer.
      clearBuffer();
      printf("Invalid entry\n");
    printf("Please enter a valid number : \n");
    }
 
      // Ouverture du fichier 1 principale en lecture et écriture.
      FILE *produit = fopen("produit.txt", "r+");

      // Ouverture du fichier temporaire en écriture.
      FILE *temp = fopen("temp.txt", "w");

    // Si un des deux fichier ne s'ouvre pas ..
    if (produit == NULL || temp == NULL) {
      printf("Error occured while opening file try again later.\n"); // Message d'erreur.
      exit(1); // Fin du programme
    }

    Produit Produit;
    
    
    while (fgets(line, sizeof(line), produit) != NULL) {
    
      
      if (numeroLigne != delete) {
        fputs(line, temp); 
        numeroLigne++; 
      }
    }
  }
  // Si l'utilisateur a fait une erreur de saisie.
  else {
    printf("Try again while the following : 'client' or 'produit'.\n"); // Demande à l'utilisateur de réessayer avec le bon orthographe.
    DeleteProduct () ;
  }
  return 0; 
}





int unitProduct(Produit produit) {
  int somme = 0;
  int quantity1 = produit.quantity1;
  int quantity2 = produit.quantity2;
  int quantity3 = produit.quantity3;
  char line[1000];
  
  FILE* fichier_produit = fopen("produit.txt", "r");
  
  if (fichier_produit == NULL) {
    printf("Error occurred while opening the file. Please try again later.\n");
    return somme;
  }
  
  while (fgets(line, sizeof(line), fichier_produit) != NULL) {
    int q1, q2, q3;
    if (sscanf(line, "%*s %*d %*f %d %*f %d %*f %d", &q1, &q2, &q3) == 3) {
      somme += q1 * 1 + q2 * 2 + q3 * 4;
    }
  }
  
  fclose(fichier_produit);
  
  printf("Quantity of products in stock is: %d\n", somme);

  // Si > 650 limite ..
  if (somme > (UNITMAX-50) && somme < UNITMAX ) {
    printf("Warning: Maximum stock limit almost reached!\n");
  } 


  // Si y a presque rien .. 
  else if (somme < 200) {
    printf("Warning: Stock is low!\n\n");
  }

  // Sinon c'est trop..
  else if ( somme > UNITMAX ) {
    printf("\n"); // Espace pour améliorer l'interface.
    printf("Stock limit reached, can't add any more products. \n");
  }
  
  return somme;
}





// Fonction pour mettre à jour l'historique d'achats des clients.
int AddPurchaseToClientProfile(const char* filename, const char* nom, const char* purchase) {
   
    FILE* fp = fopen(filename, "r+"); // Ouvre le fichier en mode lecture et écriture

  if (fp == NULL) {
    printf("Error occurred while opening file. Please try again later.\n");
    return -1;
  }

  char line[MAX_SIZE];
  int found = 0;

  while (fgets(line, sizeof(line), fp) != NULL) {
    Profile client_exist;
    sscanf(line, "%s %s %d%d %s %s %s", client_exist.nom, client_exist.prenom, &client_exist.numprofile, &client_exist.ref, client_exist.purchase1, client_exist.purchase2, client_exist.purchase3);

    // Cherche le client correspondant au nom fourni
    if (strcmp(client_exist.nom, nom) == 0) {
      found = 1;

      // Met à jour les 3 derniers achats
      strcpy(client_exist.purchase3, client_exist.purchase2);
      strcpy(client_exist.purchase2, client_exist.purchase1);
      strcpy(client_exist.purchase1, purchase);

      // Replace la ligne mise à jour dans le fichier
      fseek(fp, -strlen(line), SEEK_CUR);
      fprintf(fp, "%s %s %d %d %s %s %s\n", client_exist.nom, client_exist.prenom, client_exist.numprofile, client_exist.ref, client_exist.purchase1, client_exist.purchase2, client_exist.purchase3);
      break;
    }
  }

  fclose(fp);

  if (!found) {
    
    }
}




// Fonction pour le choix 2 clients, acheter un truc, renvoie la valeur du prix, d'ou la déclaration en float.
float Buy() {
    
  int taille;
  int ref;
  float prix;
  int code;
  char name[MAX_SIZE];
  char str_ref[MAX_SIZE];

  char stop[2] = "f";
  float ttlcost = 0;
  unsigned int count = 0;

  char line[MAX_SIZE];
  int found = 0;
  int sizeAvailable = 0;

typedef struct {
  
  char receiptNM[MAX_SIZE];
  char receiptCD[MAX_SIZE];
  float receiptPC;

} ReceiptType;

  Produit produit; // Amène le typedef struct produit.

  Profile client;
  
  ReceiptType receipt[20];

    FILE *fp = fopen("produit.txt", "r");

  
    
  // Si le fichier ne s'ouvre pas ..
  if (fp == NULL) {
    printf("Error occured while opening file try again later.\n"); // Affiche un message d'erreur.
    return 1; // return 1.
  }

    //
    while (fscanf(fp, "%s %d %f %d %f %d %f %d %s", produit.nom, &produit.ref, &produit.price1, &produit.quantity1, &produit.price2, &produit.quantity2, &produit.price3, &produit.quantity3, produit.typ) != EOF) {
        printf("| %3d | %s\n", produit.ref, produit.nom);
    }

    fclose(fp);

    do {
      printf("\n"); // Espace pour améliorer l'interface.
      printf("Please enter the item code. Type F to finish: "); // Demande la ref.
      scanf("%s", str_ref); // Récupère la réponse ref.
        
      // Convertit la chaîne de caractères en minuscules pour faciliter la comparaison.
      for (int i = 0; str_ref[i]; i++) { 
        str_ref[i] = tolower(str_ref[i]); 
      }

      //
      if (strcmp(str_ref, stop) == 0) {
        break;
      }

      ref = atoi(str_ref);

      printf("\n"); // Espace pour améliorer l'interface.
      printf("\n"); // Espace pour améliorer l'interface.
      printf("Select size: \n");
      printf("1) 50mL\n");
      printf("2) 100mL\n");
      printf("3) 200mL\n");
      scanf("%d", &taille);

        FILE *fp2 = fopen("produit.txt", "r");
        FILE *fa = fopen("temp.txt", "w");

      if (fp2 == NULL || fa == NULL) {
        printf("Error occured while opening file try again later.\n");
        return 1;
      }

      while (fgets(line, sizeof(line), fp2) != NULL) {
        sscanf(line, "%s %d %f %d %f %d %f %d %s", produit.nom, &produit.ref, &produit.price1, &produit.quantity1, &produit.price2, &produit.quantity2, &produit.price3, &produit.quantity3, produit.typ);

        //
        if (ref == produit.ref) {
          found = 1;

          //
          if (taille == 1 && produit.quantity1 > 0) {
            produit.quantity1 -= 1;
            prix = produit.price1;
            code = produit.ref;
            strcpy(name, produit.nom);
            sizeAvailable = 1;
          } 
          
          //
          else if (taille == 2 && produit.quantity2 > 0) {
            produit.quantity2 -= 1;
            prix = produit.price2;
            code = produit.ref;
            strcpy(name, produit.nom);
            sizeAvailable = 1;
          }
          
          //
          else if (taille == 3 && produit.quantity3 > 0) {
            produit.quantity3 -= 1;
            prix = produit.price3;
            code = produit.ref;
            strcpy(name, produit.nom);
            sizeAvailable = 1;
          } 
          
          //
          else {
            printf("Product selected unavailable in stock.\n");
            sizeAvailable = 0;
          }

          //
          if (sizeAvailable) {
            printf("\n"); // Espace pour améliorer l'interface.
            printf("Product: %s\n", name);
            printf("Quantity: 1\n");
            printf("Price: %.2f\n", prix);
            printf("\n"); // Espace pour améliorer l'interface.

            ttlcost += prix;
            count++;

            strcpy(receipt[count - 1].receiptNM, name);
            sprintf(receipt[count - 1].receiptCD, "%d", code);
            receipt[count - 1].receiptPC = prix;
            }

            fprintf(fa, "%s %d %.2f %d %.2f %d %.2f %d %s\n", produit.nom, produit.ref, produit.price1, produit.quantity1, produit.price2, produit.quantity2, produit.price3, produit.quantity3, produit.typ);
        }

        //
        else {
          fprintf(fa, "%s %d %.2f %d %.2f %d %.2f %d %s\n", produit.nom, produit.ref, produit.price1, produit.quantity1, produit.price2, produit.quantity2, produit.price3, produit.quantity3, produit.typ);
        }
      }

      fclose(fp2); // Fermeture du fichier 1.
      fclose(fa); // Fermeture du nouveau fichier. 

      //
      if (!found || (found && !sizeAvailable)) {
        printf("The refrence %d doesnt match products in stock or size unavailable.\n", ref);
        remove("temp.txt");
      } 

      //
      else {
        remove("produit.txt");
        rename("temp.txt", "produit.txt");
      }
    
    } while (strcmp(str_ref, stop) != 0);

    printf("__________________________________________________________________________\n");
    printf("\n"); // Espace pour améliorer l'interface.
    printf("                          THANK YOU FOR VISITING US!           \n");
    printf("__________________________________________________________________________\n");
    printf("                            * Here is your receipt: *             \n");
    printf("\n"); // Espace pour améliorer l'interface.
    printf("%18s%26s%23s\n", "Item:", "Code:", "Price:");
    printf("\n"); // Espace pour améliorer l'interface.

  for (int i = 0; i < count; i++) {
    printf("%-36s    %-3s                  %6.2f €\n", receipt[i].receiptNM, receipt[i].receiptCD, receipt[i].receiptPC);
  }

  printf("\n"); // Espace pour améliorer l'interface.
  printf("__________________________________________________________________________\n\n"); 
  printf("\n"); // Espace pour améliorer l'interface.
  printf("      Number of items: %d                    Total cost: %7.2f €     \n\n", count, ttlcost );
  printf("__________________________________________________________________________\n"); 

  // Pour historique 1
  if (count >= 1) {
    strcpy(client.purchase1, receipt[count - 1].receiptNM);
  }

  // Pour historique 2
  if (count >= 2) {
    strcpy(client.purchase2, receipt[count - 2].receiptNM);
  }

  // Pour historique 3
  if (count >= 3) {
    strcpy(client.purchase3, receipt[count - 3].receiptNM);
  }

  AddPurchaseToClientProfile("clients.txt", client.nom, receipt[count - 1].receiptNM);

  return ttlcost;
}




// Fonction pour le choix 4 client, pour supprimer son profil.
int DeleteProfile (variabletest) {
  
  int delete;
  int numeroLigne = 1;
  char line[1000];
  char type[MAX_SIZE];
  int ref;
  char str_ref[10];
  int lineNumber = 1;

  
  Profile client_exist;

  printf("\n"); // Espace pour améliorer l'interface.
 
   
  
    // Ouverture du fichier 1 principale en lecture et écriture.
    FILE *clients = fopen("clients.txt", "r+");

    // Ouverture du fichier temporaire en écriture.
    FILE *temp = fopen("temp.txt", "w");
   
  // Si un des deux fichier ne s'ouvre pas ..
  if (clients == NULL || temp == NULL) {
    printf("Error occured while opening file try again later.\n"); // Message d'erreur.
    exit(1); // Fin du programme
  }

  // Lit une ligne par une une ligne.
  while (fgets(line, sizeof(line), clients) != NULL) {

    sprintf(str_ref, "%d", variabletest);

    // Si il trouve la ref 
    if (strstr(line, str_ref) != NULL) {
      fprintf(temp, "%s %s %s %s %s %s \n", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL" ); // On écrit dans le nouveau fichier le nom et prenom par NULL.
    }

    // Sinon correspond aux autres lignes, en gros on les re écrits dans le nouveau fichier
    else {
      fputs(line, temp); // Fputs va remettre les lignes sans les modifier une par une grace à la boucle while.
    }
    
    lineNumber++; // LineNumber augmente de 1 à chaque fois pour faire l'opération avec toutes les lignes.
  }  
 
  fclose(clients); // Ferme le fichier 1.
  fclose(temp); // Ferme le fichier 2 temporaire.
  remove("clients.txt"); // Supprime l'ancien avec ligne indésirable.
  rename("temp.txt", "clients.txt"); // Renomme le nouveau fichier recopié sans la ligne indérisable comme l'ancien
 
  printf("Profile deleted succesfully.\n"); // Confirme que l'opération a fini avec succès.

  return 0;
}





// Fonction comptant le nombre de lignes dans le fichier clients.
int countline () {

  FILE *fp; // Pointeur de fichier.
  int count = 1; // Compteur de lignes.
  char filename[MAX_FILE_NAME];
  char c; // Pour stocker un caractère lu depuis le fichier.

  strcpy(filename, "clients.txt"); // On utilise strcpy pour copier une chaîne de caractères dans une autre.

  // Ouvrir le fichier en mode lecture.
  fp = fopen(filename, "r");

  // Vérifier si le fichier a été ouvert avec succès
  if (fp == NULL) {
    printf("Could not open file %s", filename); // Affiche un message d'erreur.
    return 0; //return 0
  }

  // Extraire les caractères du fichier et les stocker dans la variable c
  while ((c = getc(fp)) != EOF) {
    if (c == '\n')
      count++;
  }
   
  fclose(fp); // Fermer le fichier
  return count ;
}




int clearBuffer() {
  
  int c;
  
  printf("\n"); // Espace pour améliorer l'interface.

  //
  while ((c = getchar()) != '\n' && c != EOF) {
  }
}






int modifyproduct(Produit produit[], int num_products) {
  
  
  char search_term[50];
  printf("Enter the name or reference number of the product you are looking for : ");
  scanf("%s", search_term);
  int found = 0;
  
  FILE *f = fopen("produit.txt", "r");
  if (f == NULL) {
    printf("Product file not found.\n");
    return 0;
  }
  
  for (int i = 0; i < num_products; i++) {
  printf("went in the boucle\n");
    
    if (strcmp(produit->ref, search_term) == 0) {
      printf("Product found :\n");
      printf("  %d :  \n", produit[i].ref);
      found = 1;
      break;
    }
  }
  if (!found) {
    printf("No products match your search.\n");
  }
  
  return 0;
}




// Fonction pour stopper le programmer.
int stopProgram() {
  printf("\n"); // Espace pour améliorer l'interface.
  printf("Stopping programme.\n"); // Affiche l'arrêt du programme.
  exit(0); // Quitte le programme avec un code de sortie 0 (aucune erreur).
}








int main() {
  printf("\n");
  printf("Loading ...\n"); // Affiche chargement du programme.
  sleep(1); // patiente 1 seconde juste pour réalisme, mais utilise la bibliothèque <unistd.h>.
  printf("\n");// Esapce pour améliorer l'interface.
  EmployeeOrClient(); // Amène la fonction qui démarre le programme au début.
  return 0; 
}