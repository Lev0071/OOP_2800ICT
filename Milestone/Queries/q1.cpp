here is my understanding of the application, it all starts at:
/*L1_1*/printf("******************************\n");
/*L1_2*/printf("* Menu - Level 1             *\n");
/*L1_3*/printf("* Select an option:          *\n");
/*L1_4*/printf("* 1. Encrypt a message       *\n");
/*L1_5*/printf("* 2. Decrypt a message       *\n");
/*L1_6*/printf("* 3. Quit                    *\n");
/*L1_7*/printf("******************************\n");

it all starts at L1_4, L1_5 and ends with L1_6

selectiong opion #2 (L2_E5) before option #1 (L2_E4) for encryption. selectiong opion #2 (L2_D5) before option 1 (L2_D4) for decryption shouldl throw an exception.

I was told choosing option 3 before 1 and 2 should thrpw an exception, but Im not sure which one this is refering to so can you tell me what you think that is about and why using the comment refrences in the printf console interface shown right as the bottom.

I the user skips ahead too early, the code should not allow them and redirect them to the previous step, suing an output message (example use case you cannot encrypt and decrypt if the software's variable that contains the message is NULL or empty strin..etc), can you outline all thee chacks so the usernavigated correctly through the interface ? 

Can you respond to each statments above, you can use the references in the /**/ style coments in the interface below:

/*L1_1*/printf("******************************\n");
/*L1_2*/printf("* Menu - Level 1             *\n");
/*L1_3*/printf("* Select an option:          *\n");
/*L1_4*/printf("* 1. Encrypt a message       *\n");
/*L1_5*/printf("* 2. Decrypt a message       *\n");
/*L1_6*/printf("* 3. Quit                    *\n");
/*L1_7*/printf("******************************\n");

/*L2_E1*/printf("****************************************\n");
/*L2_E2*/printf("* Menu - Level 2: Encryption           *\n");
/*L2_E3*/printf("* Select an option:                    *\n");
/*L2_E4*/printf("* 1. Enter a message                   *\n");
/*L2_E5*/printf("* 2. One-round encryption              *\n");
/*L2_E6*/printf("* 3. Automatic multi-round encryption  *\n");
/*L2_E7*/printf("* 4. Back                               *\n");
/*L2_E8*/printf("****************************************\n");

/*L2_D1*/printf("************************************\n");
/*L2_D2*/printf("* Menu - Level 2: Decryption       *\n");
/*L2_D3*/printf("* Select an option:                *\n");
/*L2_D4*/printf("* 1. Enter a message               *\n");
/*L2_D5*/printf("* 2. Enter the round number        *\n");
/*L2_D6*/printf("* 3. For each round, print the grid*\n");
/*L2_D7*/printf("*    and the corresponding decoded *\n");
/*L2_D8*/printf("*    message                       *\n");
/*L2_D9*/printf("* 4. Back                          *\n");
/*L2_D10*/printf("************************************\n");

/*L3_E1*/printf("***********************************************\n");
/*L3_E2*/printf("* Menu - Level 3: Encryption                  *\n");
/*L3_E3*/printf("* Select an option:                           *\n");
/*L3_E4*/printf("* 1. Enter a grid size                        *\n");
/*L3_E5*/printf("* 2. Automatic grid size                      *\n");
/*L3_E6*/printf("* 3. Print the grid and the encoded message   *\n");
/*L3_E7*/printf("* 4. Back                                     *\n");
/*L3_E8*/printf("***********************************************\n");

/*L3_ME1*/printf("***********************************************\n");
/*L3_ME2*/printf("* Menu - Level 3: Encryption                  *\n");
/*L3_ME3*/printf("* Select an option:                           *\n");
/*L3_ME4*/printf("* 1. Enter the round number                   *\n");
/*L3_ME5*/printf("* 2. For each round, print the grid and       *\n");
/*L3_ME6*/printf("*    the corresponding encoded message        *\n");
/*L3_ME7*/printf("* 3. Back                                     *\n");
/*L3_ME8*/printf("***********************************************\n");
