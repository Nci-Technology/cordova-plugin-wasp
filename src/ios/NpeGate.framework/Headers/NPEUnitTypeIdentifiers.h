//
//  NPEUnitTypeIdentifiers.h
//  NpeGate
//
//  NPEGATE Copyright © 2012-2018 by North Pole Engineering, Inc.  All rights reserved.
//
//  Printed in the United States of America.  Except as permitted under the United States
//  Copyright Act of 1976, no part of this software may be reproduced or distributed in
//  any form or by any means, without the prior written permission of North Pole
//  Engineering, Inc., unless such copying is expressly permitted by federal copyright law.
//
//  Address copying inquires to:
//  North Pole Engineering, Inc.
//  npe@npe-inc.com
//  221 North First St. Ste. 310
//  Minneapolis, Minnesota 55401
//
//  Information contained in this software has been created or obtained by North Pole Engineering,
//  Inc. from sources believed to be reliable.  However, North Pole Engineering, Inc. does not
//  guarantee the accuracy or completeness of the information published herein nor shall
//  North Pole Engineering, Inc. be liable for any errors, omissions, or damages arising
//  from the use of this software.
//

#import <Foundation/Foundation.h>

typedef NSString * NPEUnitType NPE_STRING_ENUM;

/* Angular Units */
FOUNDATION_EXPORT NPEUnitType const NPEUnitTypeRadian;                       /* rad */
FOUNDATION_EXPORT NPEUnitType const NPEUnitTypeRadianPerSecond;              /* Rad/Sec */
FOUNDATION_EXPORT NPEUnitType const NPEUnitTypeDegree;                       /* ° */

/* Combined Units */
FOUNDATION_EXPORT NPEUnitType const NPEUnitTypeBeatsPerMinute;               /* BPM */
FOUNDATION_EXPORT NPEUnitType const NPEUnitTypeGramsPerDeciliter;            /* g/dl */


/* Density */
FOUNDATION_EXPORT NPEUnitType const NPEUnitTypeKilogramPerCubicMeter;        /* kg/m3 */
FOUNDATION_EXPORT NPEUnitType const NPEUnitTypeMiligramsPerCubicCentiMeter;  /* mg/cm3 */


/* NPE Generic Units */
FOUNDATION_EXPORT NPEUnitType const NPEUnitTypeDeviceNumber;                 /* # */
FOUNDATION_EXPORT NPEUnitType const NPEUnitTypeDeviceType;                   /* deviceType */
FOUNDATION_EXPORT NPEUnitType const NPEUnitTypeAcknowledgement;              /* Ack */
FOUNDATION_EXPORT NPEUnitType const NPEUnitTypeStatus;                       /* Status */
FOUNDATION_EXPORT NPEUnitType const NPEUnitTypeData;                         /* Data  */
FOUNDATION_EXPORT NPEUnitType const NPEUnitTypeIdentification;               /* ID */
FOUNDATION_EXPORT NPEUnitType const NPEUnitTypeRotations;                    /* Rotations */
FOUNDATION_EXPORT NPEUnitType const NPEUnitTypeNumber;                       /* Number */
FOUNDATION_EXPORT NPEUnitType const NPEUnitTypePacketPerSecond;              /* PPS */
FOUNDATION_EXPORT NPEUnitType const NPEUnitTypeRSSI;                         /* dBm */
FOUNDATION_EXPORT NPEUnitType const NPEUnitTypeTXPower;                      /* dBm */
FOUNDATION_EXPORT NPEUnitType const NPEUnitTypeCapabilities;                 /* Capabilities */
FOUNDATION_EXPORT NPEUnitType const NPEUnitTypeLocation;                     /* Location */
FOUNDATION_EXPORT NPEUnitType const NPEUnitTypeName;                         /* Name */
FOUNDATION_EXPORT NPEUnitType const NPEUnitTypeFlag;                         /* Flag (typically a Bool Value) */
FOUNDATION_EXPORT NPEUnitType const NPEUnitTypeMode;                         /* Mode */
FOUNDATION_EXPORT NPEUnitType const NPEUnitTypeURL;                          /* URL */
FOUNDATION_EXPORT NPEUnitType const NPEUnitTypeSerialNumber;                 /* SN - Serial Number */
FOUNDATION_EXPORT NPEUnitType const NPEUnitTypeSource;                       /* Source */
FOUNDATION_EXPORT NPEUnitType const NPEUnitTypeToken;                        /* Token */
FOUNDATION_EXPORT NPEUnitType const NPEUnitTypeArray;                        /* Array */


/* Energy Units */
FOUNDATION_EXPORT NPEUnitType const NPEUnitTypeJoules;                       /* J */
FOUNDATION_EXPORT NPEUnitType const NPEUnitTypeCalories;                     /* Calories */
FOUNDATION_EXPORT NPEUnitType const NPEUnitTypeKiloCalories;                 /* kcal */
FOUNDATION_EXPORT NPEUnitType const NPEUnitTypeTherms;                       /* Therms */
FOUNDATION_EXPORT NPEUnitType const NPEUnitTypeVoltage;                      /* V */
FOUNDATION_EXPORT NPEUnitType const NPEUnitTypeMETs;                         /* METs */
FOUNDATION_EXPORT NPEUnitType const NPEUnitTypeKCaloriesPerHour;             /* kCal/hr */


/* Force */
FOUNDATION_EXPORT NPEUnitType const NPEUnitTypeNewtons;                      /* N */
FOUNDATION_EXPORT NPEUnitType const NPEUnitTypeNewtonMeter;                  /* Nm */
FOUNDATION_EXPORT NPEUnitType const NPEUnitTypeNewtonMeterPerHertz;          /* Nm/Hz */


/* Length Units */
FOUNDATION_EXPORT NPEUnitType const NPEUnitTypeMiliMeters;                   /* mm */
FOUNDATION_EXPORT NPEUnitType const NPEUnitTypeCentiMeters;                  /* cm */
FOUNDATION_EXPORT NPEUnitType const NPEUnitTypeMeters;                       /* m */
FOUNDATION_EXPORT NPEUnitType const NPEUnitTypeKiloMeters;                   /* km */
FOUNDATION_EXPORT NPEUnitType const NPEUnitTypeMiles;                        /* mi */


/* Mass Units */
FOUNDATION_EXPORT NPEUnitType const NPEUnitTypeKiloGrams;                    /* kg */
FOUNDATION_EXPORT NPEUnitType const NPEUnitTypePounds;                       /* lb */
FOUNDATION_EXPORT NPEUnitType const NPEUnitTypeStones;                       /* st */


/* Pressure Units */
FOUNDATION_EXPORT NPEUnitType const NPEUnitTypePascal;                       /* Pa */
FOUNDATION_EXPORT NPEUnitType const NPEUnitTypeKiloPascal;                   /* kPa */
FOUNDATION_EXPORT NPEUnitType const NPEUnitTypeAtmosphere;                   /* atm */
FOUNDATION_EXPORT NPEUnitType const NPEUnitTypePSI;                          /* psi */
FOUNDATION_EXPORT NPEUnitType const NPEUnitTypeRelativeHumidity;             /* %RH */


/* Pace */
FOUNDATION_EXPORT NPEUnitType const NPEUnitTypeKiloMetersPerHour;            /* km/h */
FOUNDATION_EXPORT NPEUnitType const NPEUnitTypeMilesPerHour;                 /* MPH */
FOUNDATION_EXPORT NPEUnitType const NPEUnitTypeMetersPerSecond;              /* m/s */
FOUNDATION_EXPORT NPEUnitType const NPEUnitTypeFeetPerSecond;                /* ft/s */
FOUNDATION_EXPORT NPEUnitType const NPEUnitTypeMinutesPerMile;               /* min/mi */
FOUNDATION_EXPORT NPEUnitType const NPEUnitTypeMinutesPerKiloMeter;          /* min/km */
FOUNDATION_EXPORT NPEUnitType const NPEUnitTypeStridesPerMinute;             /* Strides/min */
FOUNDATION_EXPORT NPEUnitType const NPEUnitTypeStrokesPerMinute;             /* Strokes/min */
FOUNDATION_EXPORT NPEUnitType const NPEUnitTypeStepsPerMinute;               /* Steps/min */
FOUNDATION_EXPORT NPEUnitType const NPEUnitTypeRevolutionsPerMinute;         /* RPM */


/* Power */
FOUNDATION_EXPORT NPEUnitType const NPEUnitTypeWatts;                        /* Watt */

/* Nike */
FOUNDATION_EXPORT NPEUnitType const NPEUnitTypeFuel;                         /* Fuel */

/* Scalar Units */
FOUNDATION_EXPORT NPEUnitType const NPEUnitTypePercentage;                   /* % */
FOUNDATION_EXPORT NPEUnitType const NPEUnitTypeStrides;                      /* Strides */
FOUNDATION_EXPORT NPEUnitType const NPEUnitTypeStrokes;                      /* Strokes */
FOUNDATION_EXPORT NPEUnitType const NPEUnitTypeSteps;                        /* Steps */
FOUNDATION_EXPORT NPEUnitType const NPEUnitTypeCycles;                       /* Cycles */
FOUNDATION_EXPORT NPEUnitType const NPEUnitTypeCount;                        /* Count */


/* Temperature Units */
FOUNDATION_EXPORT NPEUnitType const NPEUnitTypeCelsius;                      /* °C */
FOUNDATION_EXPORT NPEUnitType const NPEUnitTypeFahrenheit;                   /* °F */


/* Time Units */
FOUNDATION_EXPORT NPEUnitType const NPEUnitTypeDate;                         /* Date Unit - mm/dd/yyyy */
FOUNDATION_EXPORT NPEUnitType const NPEUnitTypeTime;                         /* Time Unit - hh:mm:ss */
FOUNDATION_EXPORT NPEUnitType const NPEUnitTypeMiliSeconds;                  /* ms */
FOUNDATION_EXPORT NPEUnitType const NPEUnitTypeSeconds;                      /* sec */
FOUNDATION_EXPORT NPEUnitType const NPEUnitTypeMinutes;                      /* min */
FOUNDATION_EXPORT NPEUnitType const NPEUnitTypeHours;                        /* hour */
FOUNDATION_EXPORT NPEUnitType const NPEUnitTypeDays;                         /* day */
FOUNDATION_EXPORT NPEUnitType const NPEUnitTypeMonths;                       /* month */
FOUNDATION_EXPORT NPEUnitType const NPEUnitTypeYears;                        /* year */
FOUNDATION_EXPORT NPEUnitType const NPEUnitTypeAge;                          /* Age */


/* Volume Units */
FOUNDATION_EXPORT NPEUnitType const NPEUnitTypeLiter;                        /* L */
FOUNDATION_EXPORT NPEUnitType const NPEUnitTypeFluidOunceUS;                 /* fl_oz_us */
FOUNDATION_EXPORT NPEUnitType const NPEUnitTypeFluidOunceImperial;           /* fl_oz_imp */

/* No Units */
FOUNDATION_EXPORT NPEUnitType const NPEUnitTypeNone;

