/**
 * @function: open_door
 *            This function automatically opens the door.
 * precondition (door_locked == false && door_open == false)
 * postcondition (door_open == true)
 * invariant(door_locked)
 * returns result: 0 if success, -1 if failure
 */
int open_door(BOOL door_locked, BOOL door_open)
{
    precondition(door_locked == false && door_open == false);

    /* Operations to automatically open the door */

    if(door_locked==true &&  door_open ==false)
         door_open=true;
    else
         door_open=false;

    postcondition (door_open == true);
}


