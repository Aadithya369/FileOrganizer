sp=r"""~!@$%^&*()_-+={}|[]\:;"'<>,./1234567890#"""
solo=",".join(sp)
def validate_email(email):

    if email.count('@') != 1:
        return "invalid"
    local_part, domain_part = email.split('@')
    if not local_part or len(local_part) > 64:
        return "invalid"
    if not domain_part or len(domain_part) > 255:
        return "invalid"
    if domain_part.count('.') != 1:
        return "invalid"
    if solo in domain_part and local_part:
        return "invalid"
    if solo in email[0]:
        return "invalid"
    return "valid"
a=input()
print(validate_email(a))
