

import xml.etree.ElementTree as ET

def getClassEntity(filename):
    tree = ET.parse(filename)
    root = tree.getroot()
    #print(root.tag)try:
    return root.attrib.get('entity')
    
