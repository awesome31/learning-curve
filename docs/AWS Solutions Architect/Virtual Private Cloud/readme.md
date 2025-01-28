---
sidebar_position: 6
title: Virtual Private Cloud
---

# Virtual Private Cloud

Virtual Private Cloud or a VPC is a private network inside your AWS account. Architecting a VPC is very important.

## VPC Considerations and Design

1. What size should a VPC be? How many things can be a part of the VPC?
2. Are there any networks we can't use?
3. VPC minimum is /28 (16 IPs), maximum /16 (65536 IPs)
4. Avoid Common ranges
5. VPC Services run from within a subnet and not the VPC itself.

Lets try and break this down into step by step questions that we will ask:

1. What are the IP ranges to avoid: We can ask the business team and see the network space of any existing on premise networks.
2. Reserve 2+ Networks per region being used per account. For example, suppose we have 3 regiosn in US, 1 in Europe and Austrlia and 4 accounts then we will have 40 IP ranges setup.
3. How many subnets will you need?
4. How many IPs total? How many per subnet?
