from state import State

class GoToHomePosition(State):
    """
    The state where UR5 goes to Home position.
    """

    def on_event(self, event):
        if event == 'on_home':
            return CalculatePath()

        return self


class CalculatePath(State):
    """
    The state where it's calculated the path to be followed by the arm.
    """

    def on_event(self, event):
        if event == 'path_calculated':
            return GoToNextPoint()

        return self

class GoToNextPoint(State):
    """
    The state where the arm goes to the next path point
    """

    def on_event(self, event):
        if event == 'point_reached':
            return VerifyAlarms()
        elif event == 'path_ended':
            return Stop()
        return self

class VerifyAlarms(State):
    """
    The state where the alarms are verified
    """

    def on_event(self, event):
        if event == 'alarms_off':
            return GoToNextPoint()
        elif event == 'alarms_on':
            return VerifyAlarms()
        return self

class Stop(State):
    """
    The state where the program ends
    """

    def on_event(self, event):
        return self