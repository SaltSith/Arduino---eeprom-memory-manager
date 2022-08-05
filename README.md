# Arduino---eeprom-memory-manager

## How to use?

1. Add source data_storage.cpp, data_storage_cfg.cpp and data_storage.h to Your project
2. Define own data type in enumerate data_type_t (DS_1 and DS_LAST names are required)
3. Modify data_storage_cfg[] by adding Your data types with their sizes
  -- keep order from enumerate
  -- set address as 0
4. Create object of class data_storage
5. Call init
6. Use set to save Your data in eeprom
7. Use read to read data from eeprom
8. Change data_storage_init_value always when you change size of current data or add new between existing data
