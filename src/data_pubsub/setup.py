from setuptools import setup

package_name = 'data_pubsub'

setup(
    name=package_name,
    version='0.0.0',
    packages=[package_name],
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='bobax',
    maintainer_email='romanov.tag@mail.ru',
    description='Defender programm',
    license='Apache License 2.0',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
        	'test_sub = data_pubsub.data_sub2:main',
        	'GUI_state_talker = data_pubsub.GUI_state_pub:main',
        	'state_talker = data_pubsub.state_pub:main',
        	'talker = data_pubsub.data_pub:main',
        	'listener = data_pubsub.data_sub:main',
        	'service = data_pubsub.serverTest:main',
        	'client = data_pubsub.clientTest:main',
        ],
    },
)
