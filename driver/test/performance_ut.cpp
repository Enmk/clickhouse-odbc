#include "driver/platform/platform.h"
#include "driver/driver.h"
#include "driver/test/common_utils.h"

#include <gtest/gtest.h>

#include <cstring>

class PerformanceTest
    : public ::testing::Test
{
protected:
    virtual void SetUp() override {
        driver_log = Driver::getInstance().getAttrAs<SQLUINTEGER>(CH_SQL_ATTR_DRIVERLOG, SQL_OPT_TRACE_ON);
        if (driver_log == SQL_OPT_TRACE_ON) {
            std::cout << "Temporarily disabling driver logging..." << std::endl;
            Driver::getInstance().setAttr(CH_SQL_ATTR_DRIVERLOG, SQL_OPT_TRACE_OFF);
        }
    }

    virtual void TearDown() override {
        if (driver_log == SQL_OPT_TRACE_ON) {
            std::cout << "Re-enabling driver logging..." << std::endl;
            Driver::getInstance().setAttr(CH_SQL_ATTR_DRIVERLOG, SQL_OPT_TRACE_ON);
        }
    }

private:
    SQLUINTEGER driver_log = SQL_OPT_TRACE_ON;
};