#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STR 256

typedef struct _country_t
{
    char name[MAX_STR];
    int phone_code;
    int population;
    int square;
    char capital[MAX_STR]
} country_t;

country_t init_country(const char *_name,
                       int _phone_code,
                       int _population,
                       int _square,
                       const char *_capital)
{
    country_t tmp_return;
    char *name_dup = strdup(_name);
    char *capital_dup = strdup(_capital);

    strcpy(tmp_return.name, name_dup);
    strcpy(tmp_return.capital, capital_dup);
    tmp_return.phone_code = _phone_code;
    tmp_return.population = _population;
    tmp_return.square = _square;

    return tmp_return;
}

int read_countries(const char *filename, country_t countries[], int *count)
{
    FILE *file = fopen(filename, "r");
    if (file == NULL)
    {
        perror("Ошибка открытия файла");
        return 0;
    }

    char line[100];
    *count = 0;
    while (fgets(line, sizeof(line), file) && *count < 10)
    {
        sscanf(line, "\"%[^\"]\", %d, %d, %d, \"%[^\"]\"",
               countries[*count].name, &countries[*count].phone_code,
               &countries[*count].population, &countries[*count].square,
               countries[*count].capital);
        (*count)++;
    }

    fclose(file);
    return 1;
}

void print_country(country_t s)
{
    printf("name: %s | phone code: %d | population: %d | square: %d | capital: %s\n",
           s.name, s.phone_code, s.population, s.square, s.capital);
}

country_t *resize_arr(country_t *arr, size_t *size)
{
    country_t *tmp = (country_t *)realloc(arr, sizeof(country_t) * (*size));

    for (size_t i = 0; i < *size; i++)
        tmp[i] = arr[i];

    arr = (country_t *)realloc(tmp, sizeof(country_t) * (*size + 1));

    for (size_t i = 0; i < *size; i++)
        arr[i] = tmp[i];

    (*size)++;
}

country_t *find_country_with_bigger_population(country_t *arr_countries, size_t size_arr, int population_find, size_t* size_out)
{
    country_t *tmp = (country_t *)malloc(sizeof(country_t) * 1);
    size_t size_tmp = 0;

    for (size_t i = 0; i < size_arr; i++)
    {
        if (arr_countries[i].population > population_find)
        {
            resize_arr(tmp, &size_tmp);
            tmp[size_tmp - 1] = arr_countries[i];
        }
    }

    *size_out = size_tmp; 

    return tmp;
}

int main()
{
    const int size_vec = 10;
    country_t vec[size_vec];
    int count;

    read_countries("../country.txt", vec, &count);

    size_t size_out;
    country_t *vec_find = find_country_with_bigger_population(vec, size_vec, 126476461, &size_out);

    for (int i = 0; i < size_out; i++)
        print_country(vec_find[i]);

    return 0;
}