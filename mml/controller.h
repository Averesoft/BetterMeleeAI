/**
 * @file controller.h
 * @brief Emulate a player's controller.
 */

#ifndef MML_CONTROLLER_H
#define MML_CONTROLLER_H

#include "gctypes.h"

//@{
/** Controller bit mask */
#define BUTTON_BITS 0x000F
#define RADIUS_BITS 0x00F0
#define ANGLE_BITS  0xFF00
//@}

//@{
/** Button Flag */
#define NO_BUTTON     0x00
#define A_BUTTON      0x01
#define B_BUTTON      0x02
#define X_BUTTON      0x03
#define Z_BUTTON      0x04
#define L_BUTTON      0x05
#define START_BUTTON  0x06
#define DPAD_UP       0x07
#define DPAD_DOWN     0x08
#define DPAD_LEFT     0x09
#define DPAD_RIGHT    0x0a
#define CSTICK_UP     0x0b
#define CSTICK_DOWN   0x0c
#define CSTICK_LEFT   0x0d
#define CSTICK_RIGHT  0x0e
#define NO_STICK      0x00
#define TILT_STICK    0x10
#define FULL_STICK    0x20
//@}

/** Radius of stick that defines a tilt */
#define TILT_RADIUS 0.3

//TODO: match up with game struct
/** @brief Represents the state of a controller. */
typedef struct
{
    u32 buttons; /**< A-0100, B-0200, X-0400, Z-0010, L-0040 */

    f32 stickX; /**< x coordinate of control stick */
    f32 stickY; /**< y coordinate of control stick */

    f32 CstickX; /**< x coordinate of c-stick */
    f32 CstickY; /**< y coordinate of c-stick */

} Controller;

/** Default Controller struct */
#define DEFAULT_CONTROLLER ((Controller) {0, 0.f, 0.f, 0.f, 0.f})

/**
 * @brief Set the state of the controller.
 *
 * @param controller - Pointer to a Controller struct.
 * @param state - 16-bit integer encoding the controller state.
 * 0x000F - buttons
 * 0x00F0 - stick radius
 * 0xFF00 - stick angle
 *
 * @return None.
 */
void setController(Controller* controller, u16 state);

/**
 * @brief Write the state of @p controller to the memory addresses read
 * by the game.
 *
 * @param controller - Pointer to a Controller struct.
 * @param port - Which player port to write to {1,2,3,4}
 * @param pData - Write controller to PlayerData
 *
 * @return None
 */
void writeController(Controller* controller, u32 port, bool pData);

#endif
