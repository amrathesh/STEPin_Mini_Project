/**
 * @file inventory_manager.h
 * @author Amrathesh
 * @brief  inventory manger with four operations
 * @version 0.1
 * @date 2021-04-17
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef __INVENTORY_MANAGER_H__
#define __INVENTORY_MANAGER_H__


#include <stdio.h>
#include <stdlib.h>

struct item {
    char name[15];
    char manufacturer[25];
    int unit_cost;
    int no_avail;
};

/**
* adds item to inventory
* @param[in] FILE * pointer to datafile
* @param[in] itm pointer to item
* @return returns 0 on successful operation
*/
int additem(FILE * fp, struct item* itm);

/**
* delete item in inventory
* @param[in] itm pointer to item
* @return returns 0 on successful operation
*/
int deleteitem(struct item* itm);

/**
* modify item in inventory
* @param[in] FILE * pointer to datafile
* @return returns 0 on successful operation
*/
int modifyitem(FILE * fp);

/**
* display all items in inventory
* @param[in] FILE * pointer to datafile
* @return returns 0 on successful operation
*/
int displayitem(FILE * fp);

#endif /*#define __INVENTORY_MANAGER_H__*/
