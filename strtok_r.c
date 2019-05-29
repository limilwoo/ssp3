int main( int argc, char *argv[]) 
{
  FILE *pFile;
 // char line[100] = {0x00, };
 // char record[100][100] = {0x00, };
  char full_path[30];
  char fname[100];
  int i = 0;
  char *saveptr1;
  char *saveptr2;
  int size = 0;
  char *buffer;
  
  scanf("%s", fname);
  
  sprintf( full_path, ".//BIGFILE//%s", fname);
  
  pFile = fopen( full_path, "r");
  
  if (pFile == NULL)
    perror("file open error");
  
  fseek(pFile, 0 , SEEK_END);
  size = ftell( pFile );
  
  buffer = malloc( size + 1 );
  memset( buffer, 0 , size + 1 );
  
  printf( "File size : %d\n", size );
  
  fseek( pFile, 0, SEEK_SET); // 파일 포인터 처음으로 이동
  
  while( !feof(pFile) )
  {
    fgets ( buffer, size, pFile );
    
    char *ptr = strtok_r(buffer, "#", &saveptr1 );
    
    while( ptr != NULL )
    {
    
      char * subptr = strtok_r( ptr, ",",  &saveptr2 );
      while( subptr != NULL )
      {
        // do something
        printf(" sub : %s\n", subptr);
        subptr = strtok_r(NULL, ",",   &saveptr2 );
      }
      
        ptr = strtok_r(NULL, "#",   &saveptr1 );
    }
  
    fclose(pFile);
    
    free(buffer);
  
  return 0;
  
  }
    
    

}
