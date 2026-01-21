import neuron.api as api
from neuron.config import *
from neuron.common import *
from neuron.error import *

class TestNodeTag:


    @description(given="existent driver node", when="add tags to the node", then="add success")
    def test_add_tags_to_node(self):
        response = api.add_node_with_tags(node="modbus-tcp", plugin=PLUGIN_MODBUS_TCP, tags="tag1,tag2")
        assert 200 == response.status_code
        assert NEU_ERR_SUCCESS == response.json()['error']
        response = api.get_nodes(type=1)
        assert 200 == response.status_code
        assert "tag1,tag2" == response.json()['nodes'][0]['tags']
    
    @description(given="existent driver node with tags", when="update tags of the node", then="update success")
    def test_update_tags_of_node(self):
        response = api.update_node_tags(node="modbus-tcp", tags="tag3,tag4,tag5")
        assert 200 == response.status_code
        assert NEU_ERR_SUCCESS == response.json()['error']
        response = api.get_nodes(type=1)
        assert 200 == response.status_code
        assert "tag3,tag4,tag5" == response.json()['nodes'][0]['tags']
    
    @description(given="existent driver node with tags", when="update tags of the node to empty", then="update success")
    def test_update_tags_of_node_to_empty(self):
        response = api.update_node_tags(node="modbus-tcp", tags="")
        assert 200 == response.status_code
        assert NEU_ERR_SUCCESS == response.json()['error']
        response = api.get_nodes(type=1)
        assert 200 == response.status_code
        assert "" == response.json()['nodes'][0]['tags']
    
    @description(given="existent driver node", when="add tags with invalid symbol", then="add failed")
    def test_add_tags_with_invalid_symbol(self):
        response = api.add_node_with_tags(node="modbus-tcp-2", plugin=PLUGIN_MODBUS_TCP, tags="tag1,tag@2")
        assert 400 == response.status_code
        assert NEU_ERR_NODE_TAGS_INVALID == response.json()['error']
    
    @description(given="existent driver node", when="update tags with invalid symbol", then="update failed")
    def test_update_tags_with_invalid_symbol(self):
        response = api.add_node(node="modbus-tcp-2", plugin=PLUGIN_MODBUS_TCP)
        assert 200 == response.status_code
        assert NEU_ERR_SUCCESS == response.json()['error']
        response = api.update_node_tags(node="modbus-tcp-2", tags="tag#3,tag4")
        assert 400 == response.status_code
        assert NEU_ERR_NODE_TAGS_INVALID == response.json()['error']
    
    @description(given="existent driver node", when="add tags exceeding the limit", then="add failed")
    def test_add_tags_exceeding_limit(self):
        response = api.add_node_with_tags(node="modbus-tcp-3", plugin=PLUGIN_MODBUS_TCP, tags="tag1,tag2,tag3,tag4,tag5,tag6")
        assert 400 == response.status_code
        assert NEU_ERR_NODE_TAGS_TOO_MANY == response.json()['error']