#include "main.h"
#include "board.h"
#include "mp2664.h"
#include "hal_i2c.h"
#include <stdio.h>

int main(void)
{
    uint8_t data = 0;
    board_init();
    printf("\nStart Program!\n");
    i2c_detect();
    mp2664_read_all_register();
    while (1)
    {
        HAL_Delay(5000);
        data = mp2664_read_system_status_register();
        printf("System Status: 0x%02x\n", data);
    }
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
}
#endif /* USE_FULL_ASSERT */
