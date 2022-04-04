import py_trees

class Ping(py_trees.behaviour.Behaviour):
    def __init__(self, name="Ping"):
        """
        Default construction.
        """
        super(Ping, self).__init__(name)
        self.blackboard = self.attach_blackboard_client(name="Ping")
        self.blackboard.register_key(key="count", access=py_trees.common.Access.WRITE)
        self.blackboard.count = 0

    def setup(self):
        """
        No delayed initialisation required for this example.
        """

    def initialise(self):
        """
        Reset a variable.
        """

    def update(self):
        """
        Increment the counter and decide upon a new status result for the behaviour.
        """
        self.blackboard.count = self.blackboard.count + 1
    
        return py_trees.common.Status.SUCCESS if True else py_trees.common.Status.FAILURE

    def terminate(self, new_status):
        """
        Nothing to clean up in this example.
        """
